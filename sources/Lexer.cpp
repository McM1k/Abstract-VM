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

/****************************************************************************
 * Constructors * Constructors * Constructors * Constructors * Constructors *
 ****************************************************************************/
Lexer::Lexer(void) { // ^(((((push|assert) )(((int8|int16|int32)\([0-9]+\))|((float|double)\([0-9]+(\.[0-9]+)?\)))|pop|dump|add|sub|mul|div|mod|print|exit)?(;([[:graph:]]|[[:blank:]])*)?)|;;)(?<!^)$
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
const std::string Lexer::_commands["push", "pop", "dump", "assert", "add", "sub", "mul", "div", "mod", "print", "exit"];
const std::string Lexer::_types["int8", "int16", "int32", "float", "double"];

/*
 * is   : input stream
 * ostr : output string
 */
std::string * Lexer::splitLines(std::string is) {
    std::string *ostr;

    while(getline(is, str);
}

/*******************************************************************************
 * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions *
 *******************************************************************************/