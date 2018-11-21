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
# include "../includes/AbstractStack.hpp"
# include "../sources/LexerParserExceptions.cpp"
# include <iostream>
# include <string>
# include <list>
#include <map>

class Parser {
public:
    Parser();
    Parser(Parser const &src) = default;
    virtual ~Parser();
    Parser &operator=(Parser const &rhs) = default;

    void checkExit();
    void parseLine(std::string line);
    void executeTokens(Token command);
    void executeTokens(Token command, Token type, Token value);

    typedef void (AbstractStack::*instructAddr)();
    typedef void (AbstractStack::*instructAddrWithArgs)(IOperand const *);

private:
    AbstractStack                               *_abstractStack;
    OperandFactory const                        _factory;
    std::map<std::string, instructAddr>         _instructs;
    std::map<std::string, instructAddrWithArgs> _instructsWithArgs;
    std::map<std::string, eOperandType>         _types;
    bool                                        _exitBool;

};

#endif