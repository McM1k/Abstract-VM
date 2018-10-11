/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:19:33 by gboudrie          #+#    #+#             */
/*   Updated: 2018/03/15 18:19:33 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
# define LEXER_HPP

# include <iostream>
# include <string>
# include <list>
# include "Token.hpp"

class Lexer {
public:
    Lexer(void);
    Lexer(Lexer const &src);
    virtual ~Lexer(void);
    Lexer &operator=(Lexer const &rhs); //equals
//TODO excetpions : unknown instruction/type/broken value
    Token findComment(std::string s);
    Token findCommand(std::string s);
    Token findType(std::string s);
    Token findValue(std::string s);
    Token findSeparator(std::string s);
    Token findOpenBracket(std::string s);
    Token findCloseBracket(std::string s);

//    static const std::string *commands;
//    static const std::string *types;

private:

};

std::ostream &operator<<(std::ostream &o, Lexer const &i);


#endif