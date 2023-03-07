
// Generated from D:/4_project/CTL/compiler/CTLParser.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "CTLParser.h"


namespace ctlFront {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by CTLParser.
 */
class  CTLParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CTLParser.
   */
    virtual std::any visitMain(CTLParser::MainContext *context) = 0;


};

}  // namespace ctlFront
