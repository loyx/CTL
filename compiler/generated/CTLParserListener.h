
// Generated from D:/4_project/CTL/compiler/CTLParser.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "CTLParser.h"


namespace ctlFront {

/**
 * This interface defines an abstract listener for a parse tree produced by CTLParser.
 */
class  CTLParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterMain(CTLParser::MainContext *ctx) = 0;
  virtual void exitMain(CTLParser::MainContext *ctx) = 0;


};

}  // namespace ctlFront
