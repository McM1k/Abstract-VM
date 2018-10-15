/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractStack.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:28:13 by gboudrie          #+#    #+#             */
/*   Updated: 2018/02/18 17:28:13 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTSTACK_HPP
# define ABSTRACTSTACK_HPP
# include "IOperand.hpp"
# include "eOperandType.hpp"
# include "../exceptions/AbstractStackExceptions.epp"
# include <iostream>
# include <sstream>
# include <stack>
# include <cstdlib>

class AbstractStack {
public:
    AbstractStack(void);
    AbstractStack(AbstractStack const &src);
    virtual ~AbstractStack(void);
    AbstractStack &operator=(AbstractStack const &rhs);

    std::stack<IOperand*> getStack(void) const;


private:
    std::stack<IOperand*> _stack;

    void push(IOperand * value);
    void pop(void);
    void dump(void);
    void assert(IOperand * value) const;
    void add(void);
    void sub(void);
    void mul(void);
    void div(void);
    void mod(void);
    void print(void) const;
};

#endif