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

    splitTokens(std::list<std::string> lines);
    std::list<std::string> splitLines(iostream::istream is);
    std::list<Token> TokenizeLine(std::string str);

//    static const std::string *commands;
//    static const std::string *types;

private:
    std::list<std::string> _lines;
    std::list<Token> _tokens;

};

std::ostream &operator<<(std::ostream &o, Lexer const &i);


#endif