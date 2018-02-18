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
# include <iostream>
# include <stack>

class AbstractStack {
public:
    AbstractStack(void);
    AbstractStack(AbstractStack const &src);
    virtual ~AbstractStack(void);
    AbstractStack &operator=(AbstractStack const &rhs);

    std::stack getStack(void) const;

    class EmptyStackException : public std::exception {
    public :
        virtual const char *what() const throw();
    };
    class AssertFailExceptionException : public std::exception {
    public :
        virtual const char *what() const throw();
    };
    class StackTooShortException : public std::exception {
    public :
        virtual const char *what() const throw();
    };
    class DivByZeroException : public std::exception {
    public :
        virtual const char *what() const throw();
    };
    class NoExitInstructionException : public std::exception {
    public :
        virtual const char *what() const throw();
    };

private:
    std::stack _stack;

    void push(IOperand * value);
    void pop(void) throw(EmptyStackException);
    void dump(void);
    void assert(IOperand * value) const throw(EmptyStackException, AssertFailException);
    void add(void) throw(StackTooShortException);
    void sub(void) throw(StackTooShortException);
    void mul(void) throw(StackTooShortException);
    void div(void) throw(StackTooShortException, DivByZeroException);
    void mod(void) throw(StackTooShortException, DivByZeroException);
    void print(void) const throw(EmptyStackException, AssertFailException);
    void exit(void) const throw(NoExitInstructionException);

};

#endif