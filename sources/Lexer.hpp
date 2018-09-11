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

    //TODO : output list of strings, create that list, add it in .hpp, etc
        * splitLines(iostream::istream is);

    static const std::string *_commands;
    static const std::string *_types;

private:

};

std::ostream &operator<<(std::ostream &o, Lexer const &i);


#endif