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

class Lexer {
public:
    Lexer(void);
    Lexer(Lexer const &src);
    virtual ~Lexer(void);
    Lexer &operator=(Lexer const &rhs); //equals

    splitTokens(std::list<std::string> lines);
    std::list<std::string> splitLines(iostream::istream is);

    static const std::string *commands;
    static const std::string *types;

    //TODO : use this enum, find a way to couple it with the tokens
    // (do i get a single list of structs composed with a token and an enum value
    // or two distincts lists with splitTokens?)
    enum class eTokenType {Command, Type, Value, Comment};
private:
    std::list<std::string> _lines;

};

std::ostream &operator<<(std::ostream &o, Lexer const &i);


#endif