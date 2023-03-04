lexer grammar CTLLexer;

@lexer::postinclude {
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
}

Identifier
    : Letter LetterOrDigit*
    ;

fragment LetterOrDigit
    : Letter
    | [0-9]
    ;

fragment Letter
    : [a-zA-Z_]
    ;

//Digit: [0-9];