
// Generated from D:/4_project/CTL/compiler/CTLParser.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "CTLParserListener.h"


namespace ctlFront {

/**
 * This class provides an empty implementation of CTLParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CTLParserBaseListener : public CTLParserListener {
public:

  virtual void enterMain(CTLParser::MainContext * /*ctx*/) override { }
  virtual void exitMain(CTLParser::MainContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace ctlFront
