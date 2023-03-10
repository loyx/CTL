#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "CTLLexer.h"
#include "CTLParser.h"

using namespace antlr4;
using namespace ctlFront;

int main(int argc, char* argv[]) {

#ifdef DEBUG
    for (int i = 0; i < argc; ++i){
        std::cout <<i << ": " << argv[i] << std::endl;
    }
    std::cout << std::endl;
#endif

    std::ifstream inputFile(argv[1]);
    std::stringstream buffer;
    if (inputFile.is_open()){
        buffer << inputFile.rdbuf();

#ifdef DEBUG
        std::string content = buffer.str();
        std::cout << content << std::endl;
#endif

        inputFile.close();
    }
    std::string content = buffer.str();

    ANTLRInputStream input(content);
    CTLLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();

#ifdef DEBUG

    std::cout << "recognition clt: " << std::endl;
    for (auto &item: tokens.getTokens()) {
        std::cout << item->getText();
    }
    std::cout << "Compressed ctl:" << std::endl;
    for (auto &item: tokens.getTokens()) {
        if ((item->getType() == lexer.getTokenType("SKIP_")))
            continue;
        std::cout << item->getText();
    }

//    auto vocab = lexer.getVocabulary();
//    for (const auto &token: tokens.getTokens()){
//        std::cout << token->toString()
//        << " " << vocab.getDisplayName(token->getType())
//        << std::endl;
//    }

#endif

    std::cout << "finish compile" << std::endl;
    return 0;
}
