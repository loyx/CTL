lexer grammar CTLLexer;

@lexer::postinclude {
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
}

// Reserved
CrowdTask: 'CrowdTask';
Constraints: 'Constraints';
//Temporal: 'Temporal';
//Spatial: 'Spatial';
//Dependence: 'dependence';
//Date: 'Date';
Class: 'class';

// Separator
COLON: ':';

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

fragment
Digits
    : [0-9] ([0-9_]* [0-9])?
    ;



Identifier
    : Letter LetterOrDigit*
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