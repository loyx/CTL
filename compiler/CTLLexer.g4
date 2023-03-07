lexer grammar CTLLexer;

@lexer::postinclude {
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
}

@lexer::header {
#include "CTLParser.h"
}

@lexer::members {
private:
std::vector<std::unique_ptr<antlr4::Token>> m_tokens;
std::stack<int> m_indents;
int m_opened = 0;
std::unique_ptr<antlr4::Token> m_pLastToken = nullptr;

std::unique_ptr<antlr4::CommonToken> commonToken(size_t type, const std::string& text) {
    int stop = getCharIndex() - 1;
    int start = text.empty() ? stop: stop - text.size() + 1;
    return _factory->create({this, _input}, type, text, DEFAULT_TOKEN_CHANNEL, start, stop,
        m_pLastToken ? m_pLastToken->getLine() : 0,
        m_pLastToken ? m_pLastToken->getCharPositionInLine(): 0);
}
std::unique_ptr<antlr4::CommonToken> cloneToken(const std::unique_ptr<antlr4::Token>& source) {
  return _factory->create({ this, _input }, source->getType(), source->getText(), source->getChannel(),
  source->getStartIndex(), source->getStopIndex(), source->getLine(), source->getCharPositionInLine());
}

std::unique_ptr<antlr4::Token> createDedent(int indent) {
    std::unique_ptr<antlr4::CommonToken> dedent = commonToken(ctlParser::CTLParser::DEDENT,
        ">"+std::to_string(indent)+">");
    return dedent;
}

static int getIndentationCount(const std::string& spaces){
    int count = 0;
    for(char ch: spaces) {
        switch (ch) {
            case '\t':
                count += 8 - (count % 8);
                break;
            default:
                count++;
        }
    }
    return count;
}

public:
virtual void emit(std::unique_ptr<antlr4::Token> newToken) override {
    m_tokens.push_back(cloneToken(newToken));
    setToken(std::move(newToken));
}

std::unique_ptr<antlr4::Token> nextToken() override {
    // Check if the end-of-file is ahead and there are still some DEDENTS expected.
    if (_input->LA(1) == EOF && !m_indents.empty()) {
        // Remove any trailing EOF tokens from our buffer.
        for (int i = m_tokens.size() - 1; i >= 0; i--) {
            if (m_tokens[i]->getType() == EOF) {
                m_tokens.erase(m_tokens.begin() + i);
            }
        }

        // First emit an extra line break that serves as the end of the statement.
        emit(commonToken(NEWLINE, "\n"));

        // Now emit as much DEDENT tokens as needed.
        while (!m_indents.empty()) {
            emit(createDedent(0));
            emit(commonToken(SKIP_, "\n"));
            m_indents.pop();
        }

        // Put the EOF back on the token stream.
        emit(commonToken(EOF, "<EOF>"));
    }

    std::unique_ptr<antlr4::Token> next = Lexer::nextToken();

    if (next->getChannel() == antlr4::Token::DEFAULT_CHANNEL) {
        // Keep track of the last token on the default channel.
        m_pLastToken = cloneToken(next);
    }

    if (!m_tokens.empty()) {
        next = std::move(*m_tokens.begin());
        m_tokens.erase(m_tokens.begin());
    }

    return next;
}

}

// Reserved
CrowdTask: 'CrowdTask';
Constraints: 'Constraints';
Class: 'class';

// Separator
LPAREN: '(' {m_opened++;};
RPAREN: ')' {m_opened--;};
LBRACE: '{' {/*m_opened++;*/};
RBRACE: '}' {/*m_opened--;*/};
LBRACK: '[' {m_opened++;};
RBRACK: ']' {m_opened--;};
//SEMI: ';';
COMMA: ',';
DOT: '.';
COLON: ':';

// Operators

ASSIGN: '=';
GT: '>';
LT: '<';
EQUAL: '==';
GE: '>=';
LE: '<=';
NOTEQUAL: '!=';

AND: '&&';
OR: '||';

ADD: '+';
SUB: '-';
MUL: '*';
DIV: '/';
MOD: '%';

ARROW: '->';


// literals
IntegerLiteral
    : DecimalLiteral
    | HexLiteral
    | OctLiteral
    ;

DecimalLiteral
    : ('0' | [1-9] ((Digits)? | '_'+ Digits)) [lL]?
    ;

HexLiteral
    : '0' [xX] [0-9a-fA-F] ([0-9a-fA-F_]* [0-9a-fA-F])? [lL]?
    ;

OctLiteral
    : '0' '_'* [0-7] ([0-7_]* [0-7])? [lL]?
    ;

FloatLiteral
    : (Digits '.' Digits ? | '.' Digits) ExponetPart? [fFdD]?
    | Digits (ExponetPart [fFdD] ? | [fFdD])
    ;

HexFLoatLiteral
    : '0' [xX] (HexDigits '.'? | HexDigits? '.' HexDigits) [pP] [+-]? Digits [fFdD]?
    ;

StringLiteral
    : '"' StringElement* '"'
    ;

BoolLiteral
    : 'true'
    | 'false'
    ;

// id

Identifier
    : Letter LetterOrDigit*
    ;

// NEWLINE
NEWLINE
    : ('\r'? '\n' | '\r' | '\f') SPACES? {
        {
            std::string newline, spaces;
            std::string text = getText();
            for (char c: text){
                if ((c == '\r') || (c == '\n') || (c == '\f')) {
                    newline.push_back(c);
                } else {
                    spaces.push_back(c);
                }
            }
            int next = _input->LA(1);
            int nextnext = _input->LA(2);
            if (m_opened > 0 || (nextnext != -1 && (next == '\r' || next == '\n' ||next == '\f' ||next == '#' ) ) ) {
                // The part of the block that requires indentation to distinguish code exists
                // only within the CrowdTask, where m_opened is 1
                emit(commonToken(SKIP_, newline));
            } else {
                int indent = getIndentationCount(spaces);
                int previous = m_indents.empty() ? 0 : m_indents.top();
                if (indent == previous){
                    emit(commonToken(SKIP_, text));
                } else if(indent > previous) {
                    emit(commonToken(NEWLINE, ";" + newline));
                    m_indents.push(indent);
                    emit(commonToken(SKIP_, spaces));
                    emit(commonToken(ctlParser::CTLParser::INDENT, "<"+ std::to_string(indent)+"<"));
                } else {
                    emit(commonToken(NEWLINE, ";" + newline));
                    while (!m_indents.empty() && m_indents.top() > indent) {
                        emit(commonToken(SKIP_, std::string(m_indents.top(), ' ')));
                        emit(createDedent(m_indents.top()));
                        emit(commonToken(SKIP_, "\n"));
                        m_indents.pop();
                    }
                    emit(commonToken(SKIP_, std::string(indent, ' ')));
                }
            }
        }
    }
    ;

// Whitespace
SKIP_: (SPACES) -> channel(HIDDEN);

// fragments

fragment
SPACES
    : [ \t]+
    ;

fragment
StringElement
    : '\u0020' | '\u0021' | '\u0023' .. '\u007F' | CharEscapeSeq
    ;

fragment
CharEscapeSeq
    : '\\' ('b' | 't' | 'n' | 'f' | 'r' | '"' | '\'' | '\\')
    ;

fragment
HexDigits
    : HexDigit ((HexDigit | '_')* HexDigit)?
    ;

fragment
HexDigit
    : [0-9a-fA-F]
    ;

fragment
ExponetPart
    : [eE] [+-]? Digits
    ;

fragment
Digits
    : [0-9] ([0-9_]* [0-9])?
    ;

fragment
LetterOrDigit
    : Letter
    | [0-9]
    ;

fragment
Letter
    : [a-zA-Z_]
    ;

//Digit: [0-9];