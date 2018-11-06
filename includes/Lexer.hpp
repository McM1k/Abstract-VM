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
# include "../exceptions/LexerParserExceptions.epp"

class Lexer {
public:
    Lexer(void);
    Lexer(Lexer const &src);
    virtual ~Lexer(void);
    Lexer &operator=(Lexer const &rhs); //equals
    Token static findComment(std::string s);
    Token static findCommand(std::string s);
    Token static findType(std::string s);
    Token static findValue(std::string s);
    Token static findSeparator(std::string s);
    Token static findOpenBracket(std::string s);
    Token static findCloseBracket(std::string s);

//    static const std::string *commands;
//    static const std::string *types;

private:

};

std::ostream &operator<<(std::ostream &o, Lexer const &i);


#endif