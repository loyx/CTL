#include <iostream>
#include "antlr4-runtime.h"
#include "CTLLexer.h"
#include "CTLParser.h"

using namespace antlr4;
using namespace ctlLexer;

int main(int argc, char* argv[]) {

#ifdef DEBUG
    for (int i = 0; i < argc; ++i){
        std::cout <<i << ": " << argv[i] << std::endl;
    }
#endif

    ANTLRInputStream input("a123");
    CTLLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();

#ifdef DEBUG
    for (const auto &token: tokens.getTokens()){
        std::cout << token->toString() << std::endl;
    }
#endif

    std::cout << "finish compile" << std::endl;
    return 0;
}
