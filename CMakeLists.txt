cmake_minimum_required(VERSION 3.9)
project(abstract_vm_GH)

set(CMAKE_CXX_STANDARD 11)

set(sourceCode sources/OperandFactory.cpp sources/Lexer.cpp sources/Parser.cpp sources/Token.cpp sources/AbstractStack.cpp sources/Operand.tpp)

set(HEADER_FILES sources/OperandFactory.hpp sources/Lexer.hpp sources/Parser.hpp sources/Token.hpp sources/AbstractStack.hpp sources/IOperand.hpp sources/eOperandType.hpp)

add_executable(abstract_vm ${HEADER_FILES} sources/main.cpp ${sourceCode})
