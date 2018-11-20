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
# include "../sources/AbstractStackExceptions.cpp"
# include "../sources/OperandExceptions.cpp"
# include <iostream>
# include <sstream>
# include <stack>
# include <cstdlib>

class AbstractStack {
public:
    AbstractStack() = default;
    AbstractStack(AbstractStack const &src) = default;
    virtual ~AbstractStack();
    AbstractStack &operator=(AbstractStack const &rhs);

    std::stack<IOperand const *> getStack() const;

    void push(IOperand const * value);
    void pop();
    void dump();
    void assert(IOperand const * value);
    void add();
    void sub();
    void mul();
    void div();
    void mod();
    void print();
private:
    std::stack<IOperand const *> _stack{};
};

#endif