
#include "CTLParser.h"


// Generated from D:/4_project/CTL/compiler/CTLLexer.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"


#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif


namespace ctlFront {


class  CTLLexer : public antlr4::Lexer {
public:
  enum {
    CrowdTask = 1, Constraints = 2, Class = 3, LPAREN = 4, RPAREN = 5, LBRACE = 6, 
    RBRACE = 7, LBRACK = 8, RBRACK = 9, COMMA = 10, DOT = 11, COLON = 12, 
    ASSIGN = 13, GT = 14, LT = 15, EQUAL = 16, GE = 17, LE = 18, NOTEQUAL = 19, 
    AND = 20, OR = 21, ADD = 22, SUB = 23, MUL = 24, DIV = 25, MOD = 26, 
    ARROW = 27, IntegerLiteral = 28, DecimalLiteral = 29, HexLiteral = 30, 
    OctLiteral = 31, FloatLiteral = 32, HexFLoatLiteral = 33, StringLiteral = 34, 
    BoolLiteral = 35, Identifier = 36, NEWLINE = 37, SKIP_ = 38
  };

  explicit CTLLexer(antlr4::CharStream *input);

  ~CTLLexer() override;


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
      std::unique_ptr<antlr4::CommonToken> dedent = commonToken(ctlFront::CTLParser::DEDENT,
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



  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void LPARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void RPARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void LBRACEAction(antlr4::RuleContext *context, size_t actionIndex);
  void RBRACEAction(antlr4::RuleContext *context, size_t actionIndex);
  void LBRACKAction(antlr4::RuleContext *context, size_t actionIndex);
  void RBRACKAction(antlr4::RuleContext *context, size_t actionIndex);
  void NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace ctlFront
