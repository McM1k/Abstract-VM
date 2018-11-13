cmake_minimum_required(VERSION 3.9)
project(abstract_vm_GH)

set(CMAKE_CXX_STANDARD 11)

set(sourceCode sources/FileHandler.cpp sources/OperandFactory.cpp sources/Lexer.cpp sources/Parser.cpp sources/Token.cpp sources/AbstractStack.cpp sources/Operand.cpp)

set(HEADER_FILES includes/FileHandler.hpp includes/OperandFactory.hpp includes/Lexer.hpp includes/Parser.hpp includes/Token.hpp includes/AbstractStack.hpp includes/IOperand.hpp includes/eOperandType.hpp)

add_executable(abstract_vm ${HEADER_FILES} sources/main.cpp ${sourceCode})
