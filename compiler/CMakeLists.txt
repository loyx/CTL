cmake_minimum_required(VERSION 3.24)
find_package(Java 17 REQUIRED)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

project(CTLCompiler)

# compiler flag
if (DEBUG)
    message("Enable debug mode")
    add_compile_definitions(DEBUG)
endif ()

set(CMAKE_CXX_STANDARD 17)
set(ANTLR4_WITH_STATIC_CRT OFF)

add_definitions(-DANTLR4CPP_STATIC)

include(ExternalAntlr4Cpp)
include_directories(${ANTLR4_INCLUDE_DIRS})

# antlr generated files
set(ANTLR_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/antlr-4.12.0-complete.jar)
set(GENERATED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/generated)
set(antlr4-CTL-GENERATED_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/generated/CTLLexer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/generated/CTLParser.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/generated/CTLParserBaseListener.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/generated/CTLParserBaseVisitor.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/generated/CTLParserListener.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/generated/CTLParserVisitor.cpp
        )
foreach(src_file ${antlr4-CTL-GENERATED_SRC})
    set_source_files_properties(
            ${src_file}
            PROPERTIES
            GENERATED TRUE
    )
endforeach()

add_custom_target(GenerateParser DEPENDS ${antlr4-CTL-GENERATED_SRC})
add_custom_command(OUTPUT ${antlr4-CTL-GENERATED_SRC}
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_SOURCE_DIR}/generated
        COMMAND ${Java_JAVA_EXECUTABLE} -jar ${ANTLR_EXECUTABLE}
            -Dlanguage=Cpp
            -listener
            -visitor
            -o ${CMAKE_CURRENT_SOURCE_DIR}/generated
            -package ctlFront
            ${CMAKE_CURRENT_SOURCE_DIR}/CTLLexer.g4
            ${CMAKE_CURRENT_SOURCE_DIR}/CTLParser.g4
        WORKING_DIRECTORY .
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/CTLLexer.g4 ${CMAKE_CURRENT_SOURCE_DIR}/CTLParser.g4
        )

include_directories(
        ${GENERATED_DIR}
)

add_executable(ctlc main.cpp
        ${antlr4-CTL-GENERATED_SRC}
        )

add_dependencies(
        ctlc GenerateParser
)

target_link_libraries(ctlc antlr4_static)
