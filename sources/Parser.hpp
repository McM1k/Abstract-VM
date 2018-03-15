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

class Parser {
public:
    Parser(void);

    Parser(Parser const &src);

    virtual ~Parser(void);

    Parser &operator=(Parser const &rhs); //equals


private:

};

std::ostream &operator<<(std::ostream &o, Parser const &i);


#endif