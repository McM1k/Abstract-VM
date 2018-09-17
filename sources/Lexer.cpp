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
//^(push|assert|pop|dump|print|add|sub|mul|div|mod|exit|;;)

// TYPE        const std::string Lexer::types["int8", "int16", "int32", "float", "double"];
// (int8|int16|int32|float|double)

// VALUE
//\(([0-9])+(\.([0-9])+)?\)

//COMMENT
//;|$

std::list<std::string> Lexer::splitLines(std::string is) {
    std::string str;
    std::list<std::string> lines;

    while(getline(is, str){
        lines.push_back(str);
    }

//    this->_lines = lines;
    return lines;
}

std::list<Token> Lexer::TokenizeLine(std::string str) {
    std::list<Token> tokens;

    if (std::regex_match(str,"^(push|assert|pop|dump|print|add|sub|mul|div|mod|exit|;;)")){
        //TODO : do stuff

        str.erase(0, token.content.size());
    }
    else{
        //TODO : throw an exception
    }
    return tokens;
}

/*******************************************************************************
 * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions *
 *******************************************************************************/