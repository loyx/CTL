lexer grammar CTLLexer;

@lexer::postinclude {
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
}

// Reserved
CrowdTask: 'CrowdTask';
Constraints: 'Constraints';
Class: 'class';

// Separator
LPAREN: '(';
RPAREN: ')';
LBRACE: '{';
RBRACE: '}';
LBRACK: '[';
RBRACK: ']';
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


// fragments

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