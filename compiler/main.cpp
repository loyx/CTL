#include <iostream>
#include "antlr4-runtime.h"
#include "CTLLexer.h"
#include "CTLParser.h"

using namespace antlr4;
using namespace ctlLexer;

int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; ++i){
        std::cout <<i << ": " << argv[i] << std::endl;
    }
    ANTLRInputStream input("a123");
    CTLLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    for (const auto &token: tokens.getTokens()){
        std::cout << token->toString() << std::endl;
    }
    std::cout << "finish" << std::endl;
    return 0;
}
