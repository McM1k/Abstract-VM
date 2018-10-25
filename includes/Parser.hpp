/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:19:40 by gboudrie          #+#    #+#             */
/*   Updated: 2018/03/15 18:19:40 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP
# include "../includes/Token.hpp"
# include "../includes/Lexer.hpp"
# include "../includes/IOperand.hpp"
# include "../includes/OperandFactory.hpp"
# include "../includes/eOperandType.hpp"
# include <iostream>
# include <string>
# include <list>
#include <map>

class Parser {
public:
    Parser(void);
    Parser(Parser const &src);
    virtual ~Parser(void);
    Parser &operator=(Parser const &rhs);

    std::list<std::string> splitLines(std::istream is);
    void parseNextLine(std::list<std::string> *lines);
    void executeTokens(Token command);
    void executeTokens(Token command, Token type, Token value);
    //TODO function that reads while theres still lines



    //TODO exception missing exit
private:
    OperandFactory const _factory;
    std::list<std::string> _lines;
    std::map<std::string, ???> _instructs;
    std::map<std::string, ???WithArgs> _instructsWithArgs;
    std::map<std::string, eOperandType> _types;
    //TODO map<string, funct>

};

std::ostream &operator<<(std::ostream &o, Parser const &i);


#endif