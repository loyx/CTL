parser grammar CTLParser;

//options {tokenVocab=CTLLexer;}
tokens {INDENT, DEDENT}

main: Identifier;