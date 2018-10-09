/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:18:13 by gboudrie          #+#    #+#             */
/*   Updated: 2018/03/15 18:18:13 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"
#include <iostream>
#include <string>
#include <list>
#include <regex>

/****************************************************************************
 * Constructors * Constructors * Constructors * Constructors * Constructors *
 ****************************************************************************/
Lexer::Lexer(void) {
    // std::cout << "An instance of Lexer has been created" << std::endl;

}

Lexer::Lexer(Lexer const &src) {
    //std::cout << "An instance of Lexer has been created by copy" << std::endl;
    *this = src;
}

/***********************************************************************
 * Destructors * Destructors * Destructors * Destructors * Destructors *
 ***********************************************************************/
Lexer::~Lexer(void) {
    //std::cout << "An instance of Lexer has been destroyed" << std::endl;
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
Lexer &Lexer::operator=(Lexer const &rhs) {
    if (this != &rhs) {
        //this->XXX = rhs.getXXX();
    }
    return *this;
}

/******************************************************************************
 * ToString * ToString * ToString * ToString * ToString * ToString * ToString *
 ******************************************************************************/
std::ostream &operator<<(std::ostream &o, Lexer const &i) {
    o << "no attributes" << std::endl;
    return o;
}

/*************************************************************************
 * Other * Other * Other * Other * Other * Other * Other * Other * Other *
 *************************************************************************/

// COMMAND     const std::string Lexer::commands["push", "pop", "dump", "assert", "add", "sub", "mul", "div", "mod", "print", "exit"];
//^(push|assert|pop|dump|print|add|sub|mul|div|mod|exit)

// SEPARATOR
//^

// TYPE        const std::string Lexer::types["int8", "int16", "int32", "float", "double"];
//^(int8|int16|int32|float|double)

// VALUE
//^([0-9])+(\.([0-9])+)?

// OPENBRACKET
//^(

// CLOSEBRACKET
//^)

//COMMENT
//;([[:print:]])*

Token Lexer::findComment(std::string s) {
    std::smatch sm;
    std::regex rgx(";([[:print:]])*");

    std::regex_search(s, sm, rgx);
    return Token(sm[0], Token::eTokenType::comment);
}

Token Lexer::findSeparator(std::string s) {
    std::smatch sm;
    std::regex rgx("^ ");

    std::regex_search(s, sm, rgx);
    return Token(sm[0], Token::eTokenType::separator);
}

Token Lexer::findOpenBracket(std::string s) {
    std::smatch sm;
    std::regex rgx("^\\(");

    std::regex_search(s, sm, rgx);
    return Token(sm[0], Token::eTokenType::openBracket);
}

Token Lexer::findCloseBracket(std::string s) {
    std::smatch sm;
    std::regex rgx("^\\)");

    std::regex_search(s, sm, rgx);
    return Token(sm[0], Token::eTokenType::closeBracket);
}

Token Lexer::findCommand(std::string s) {
    std::smatch sm;
    std::regex rgx("^(push|assert|pop|dump|print|add|sub|mul|div|mod|exit)");

    std::regex_search(s, sm, rgx);
    return Token(sm[0], Token::eTokenType::command);
}

Token Lexer::findType(std::string s) {
    std::smatch sm;
    std::regex rgx("^(int8|int16|int32|float|double)");

    std::regex_search(s, sm, rgx);
    return Token(sm[0], Token::eTokenType::type);
}

Token Lexer::findValue(std::string s) {
    std::smatch sm;
    std::regex rgx("^([0-9])+(\\.([0-9])+)?");

    std::regex_search(s, sm, rgx);
    return Token(sm[0], Token::eTokenType::value);
}

/*******************************************************************************
 * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions *
 *******************************************************************************/