/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:19:38 by gboudrie          #+#    #+#             */
/*   Updated: 2018/03/15 18:19:38 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Parser.hpp"

/****************************************************************************
 * Constructors * Constructors * Constructors * Constructors * Constructors *
 ****************************************************************************/
Parser::Parser() {
    this->_abstractStack = new AbstractStack();
    this->_types["int8"] = eOperandType::Int8;
    this->_types["int16"] = eOperandType::Int16;
    this->_types["int32"] = eOperandType::Int32;
    this->_types["float"] = eOperandType::Float;
    this->_types["double"] = eOperandType::Double;
    this->_instructs["pop"] = &AbstractStack::pop;
    this->_instructs["dump"] = &AbstractStack::dump;
    this->_instructs["print"] = &AbstractStack::print;
    this->_instructs["add"] = &AbstractStack::add;
    this->_instructs["sub"] = &AbstractStack::sub;
    this->_instructs["mul"] = &AbstractStack::mul;
    this->_instructs["div"] = &AbstractStack::div;
    this->_instructs["mod"] = &AbstractStack::mod;
    this->_instructsWithArgs["push"] = &AbstractStack::push;
    this->_instructsWithArgs["assert"] = &AbstractStack::assert;

    this->_exitBool = false;
}

Parser::Parser(Parser const &src) {
    //std::cout << "An instance of Parser has been created by copy" << std::endl;
    *this = src;
}

/***********************************************************************
 * Destructors * Destructors * Destructors * Destructors * Destructors *
 ***********************************************************************/
Parser::~Parser() {
    if (!this->_exitBool)
        throw MissingExitException();
}

/***********************************************************************
 * Getters * Getters * Getters * Getters * Getters * Getters * Getters *
 ***********************************************************************/

/***********************************************************************
 * Setters * Setters * Setters * Setters * Setters * Setters * Setters *
 ***********************************************************************/

/*************************************************************************
 * Operators * Operators * Operators * Operators * Operators * Operators *
 *************************************************************************/
Parser &Parser::operator=(Parser const &rhs) {
    if (this != &rhs) {
        //this->XXX = rhs.getXXX();
    }
    return *this;
}

/******************************************************************************
 * ToString * ToString * ToString * ToString * ToString * ToString * ToString *
 ******************************************************************************/


/*************************************************************************
 * Other * Other * Other * Other * Other * Other * Other * Other * Other *
 *************************************************************************/
//std::list<std::string> Parser::stockLines(/*file*/) {
//    std::string str;
//    std::list<std::string> lines;
//
//    while (getline(file.firstLine, str)){
//
//    }
//}
//
//std::list<std::string> Parser::splitLines(std::istream is) {
//    std::string str;
//    std::list<std::string> lines;
//
//    while(getline(is, str)){
//        lines.push_back(str);
//    }
//
//    lines = this->_lines;
//    return lines;
//}

void Parser::parseLine(std::string line) {
    Token throwableTk;
    Token commandTk;
    Token typeTk;
    Token valueTk;

    throwableTk = Lexer::findComment(line);
    size_t pos = line.find(throwableTk.getContent());
    line.erase(pos, throwableTk.getContent().length());
    if (line.length() == 0) { return; }
    if (_exitBool) { throw CommandAfterExitException(); }

    try {
        commandTk = Lexer::findCommand(line);
    } catch (const UnknownCommandException &e) {
        std::cerr << e.what() << std::endl;
    }
    line.erase(0, commandTk.getContent().length());

    if (commandTk.getContent() == "push" || commandTk.getContent() == "assert") {
        throwableTk = Lexer::findSeparator(line);
        if (throwableTk.getContent().length() == 0)
            throw SyntaxErrorException();
        line.erase(0, 1);//faster than getting length

        try {
            typeTk = Lexer::findType(line);
            line.erase(0, typeTk.getContent().length());
        } catch (const UnknownTypeException &e) {
            std::cerr << e.what() << std::endl;
        }

        throwableTk = Lexer::findOpenBracket(line);
        if (throwableTk.getContent().length() == 0)
            throw SyntaxErrorException();
        line.erase(0, 1);

        try {
            valueTk = Lexer::findValue(line);
            line.erase(0, valueTk.getContent().length());
        } catch (const BadValueException &e) {
            std::cerr << e.what() << std::endl;
        }

        throwableTk = Lexer::findCloseBracket(line);
        if (throwableTk.getContent().length() == 0)
            throw SyntaxErrorException();
        line.erase(0, 1);

        if (line.length()) {
            throw SyntaxErrorException();
        }
        executeTokens(commandTk, typeTk, valueTk);
    } else if (commandTk.getContent() == "exit") { this->_exitBool = true; }
    else {
        if (line.length()) {
            throw SyntaxErrorException();
        }
        executeTokens(commandTk);
    }
}

void Parser::executeTokens(Token command) {
    try {
        (_abstractStack->*(this->_instructs[command.getContent()]))();
    } catch (const EmptyStackException& e)      {
        std::cerr << e.what() << std::endl;
    } catch (const NotPrintableException& e)    {
        std::cerr << e.what() << std::endl;
    } catch (const StackTooShortException& e)   {
        std::cerr << e.what() << std::endl;
    } catch (const OverFlowException& e)        {
        std::cerr << e.what() << std::endl;
    } catch (const UnderFlowException& e)       {
        std::cerr << e.what() << std::endl;
    } catch (const DivideByZeroException& e)    {
        std::cerr << e.what() << std::endl;
    } catch (const ModOnFloatException& e)      {
        std::cerr << e.what() << std::endl;
    } catch (const std::exception& e)           {
        std::cerr << e.what() << std::endl;
    }
}

void Parser::executeTokens(Token command, Token type, Token value) {
    try {
        IOperand const *operand = this->_factory.createOperand(this->_types[type.getContent()], value.getContent());
        (_abstractStack->*(this->_instructsWithArgs[command.getContent()]))(operand);
    } catch (const EmptyStackException& e)      {
        std::cerr << e.what() << std::endl;
    } catch (const UnderFlowException& e)       {
        std::cerr << e.what() << std::endl;
    } catch (const OverFlowException& e)        {
        std::cerr << e.what() << std::endl;
    } catch (const AssertFailException& e)      {
        std::cerr << e.what() << std::endl;
    } catch (const std::exception e)            {
        std::cerr << e.what() << std::endl;
    }

}

/*******************************************************************************
 * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions *
 *******************************************************************************/