cmake_minimum_required(VERSION 3.24)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

project(CTLCompiler)

# compiler flag
if (DEBUG)
    message("Enable debug mode")
    add_compile_definitions(DEBUG)
endif ()

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DANTLR4CPP_STATIC)
set(ANTLR4_WITH_STATIC_CRT OFF)

include(ExternalAntlr4Cpp)
include_directories(${ANTLR4_INCLUDE_DIRS})

set(ANTLR_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/antlr-4.12.0-complete.jar)
find_package(ANTLR REQUIRED)

antlr_target(CTLLexer ${CMAKE_CURRENT_SOURCE_DIR}/CTLLexer.g4 LEXER
        PACKAGE ctlLexer)
antlr_target(CTLParser ${CMAKE_CURRENT_SOURCE_DIR}/CTLParser.g4 PARSER
        PACKAGE ctlParser
        DEPENDS_ANTLR CTLLexer
        COMPILER_FLAGS -lib ${ANTLR_CTLLexer_OUTPUT_DIR})

include_directories(${ANTLR_CTLLexer_OUTPUT_DIR})
include_directories(${ANTLR_CTLParser_OUTPUT_DIR})

add_executable(ctlc main.cpp
        ${ANTLR_CTLLexer_CXX_OUTPUTS}
        ${ANTLR_CTLParser_CXX_OUTPUTS})
target_link_libraries(ctlc antlr4_static)
