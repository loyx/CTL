
// Generated from D:/4_project/CTL/compiler/CTLParser.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "CTLParserVisitor.h"


namespace ctlFront {

/**
 * This class provides an empty implementation of CTLParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CTLParserBaseVisitor : public CTLParserVisitor {
public:

  virtual std::any visitMain(CTLParser::MainContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace ctlFront
