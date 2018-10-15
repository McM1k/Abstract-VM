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

# include <iostream>
# include <string>
# include <list>

class Parser {
public:
    Parser(void);
    Parser(Parser const &src);
    virtual ~Parser(void);
    Parser &operator=(Parser const &rhs); //equals

    std::list<std::string> splitLines(iostream::istream is);
    void executeNextLine(std::list<std::string> *lines); //TODO throws stuff
    //TODO function that reads while theres still lines

    //TODO exceptions syntax error, missing exit
private:
    std::list<std::string> _lines;
    //TODO map<string, funct>

};

std::ostream &operator<<(std::ostream &o, Parser const &i);


#endif