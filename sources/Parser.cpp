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
Parser::Parser(void) {
    //TODO cosntruct map with tokens and corresponding keywords

}

Parser::Parser(Parser const &src) {
    //std::cout << "An instance of Parser has been created by copy" << std::endl;
    *this = src;
}

/***********************************************************************
 * Destructors * Destructors * Destructors * Destructors * Destructors *
 ***********************************************************************/
Parser::~Parser(void) {
    //std::cout << "An instance of Parser has been destroyed" << std::endl;
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
std::ostream &operator<<(std::ostream &o, Parser const &i) {
    o << "no attributes" << std::endl;
    return o;
}

/*************************************************************************
 * Other * Other * Other * Other * Other * Other * Other * Other * Other *
 *************************************************************************/
std::list<std::string> Parser::splitLines(std::istream is) {
    std::string str;
    std::list<std::string> lines;

    while(getline(is, str)){
        lines.push_back(str);
    }

    lines = this->_lines;
    return lines;
}

void Parser::parseNextLine(std::list<std::string> *lines) {
    std::string line = lines->front();
    Token throwableTk;
    Token commandTk;
    Token typeTk;
    Token valueTk;

    throwableTk = Lexer::findComment(line);
    size_t pos = line.find(throwableTk.getContent());
    line.erase(pos, throwableTk.getContent().length());
    if (line.length()){
        lines->pop_front();
        return;
    }

    commandTk = Lexer::findCommand(line);
    line.erase(0, commandTk.getContent().length());

    if (commandTk.getContent() == "push" || commandTk.getContent() == "assert") {
        throwableTk = Lexer::findSeparator(line);
        if (throwableTk.getContent().length() == 0)
            throw SyntaxErrorException();
        line.erase(0, 1);//faster than getting length

        typeTk = Lexer::findType(line);
        line.erase(0, typeTk.getContent().length());

        throwableTk = Lexer::findOpenBracket(line);
        if (throwableTk.getContent().length() == 0)
            throw SyntaxErrorException();
        line.erase(0, 1);

        valueTk = Lexer::findValue(line);
        line.erase(0, valueTk.getContent().length());

        throwableTk = Lexer::findCloseBracket(line);
        if (throwableTk.getContent().length() == 0)
            throw SyntaxErrorException();
        line.erase(0, 1);
    }
    else {
        typeTk = Token("", Token::eTokenType::none);
        valueTk = typeTk;
    }

    if (line.length()){
        throw SyntaxErrorException();
    }
    executeTokens(commandTk, typeTk, valueTk);
}

void Parser::executeTokens(Token command, Token type, Token value) {
    if (type.getType() == Token::eTokenType::none){

    } else
}

/*******************************************************************************
 * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions *
 *******************************************************************************/