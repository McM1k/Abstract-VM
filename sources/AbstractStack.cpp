/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractStack.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:27:25 by gboudrie          #+#    #+#             */
/*   Updated: 2018/02/18 17:27:25 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AbstractStack.hpp"
#include "../exceptions/AbstractStackExceptions.epp"
#include <iostream>

/****************************************************************************
 * Constructors * Constructors * Constructors * Constructors * Constructors *
 ****************************************************************************/

AbstractStack::AbstractStack(AbstractStack const &src) {
    *this = src;
}

/***********************************************************************
 * Destructors * Destructors * Destructors * Destructors * Destructors *
 ***********************************************************************/
AbstractStack::~AbstractStack(void) {}

/***********************************************************************
 * Getters * Getters * Getters * Getters * Getters * Getters * Getters *
 ***********************************************************************/
std::stack<IOperand*> AbstractStack::getStack() const {
    return this->_stack;
}

/***********************************************************************
 * Setters * Setters * Setters * Setters * Setters * Setters * Setters *
 ***********************************************************************/

/*************************************************************************
 * Operators * Operators * Operators * Operators * Operators * Operators *
 *************************************************************************/
AbstractStack &AbstractStack::operator=(AbstractStack const &rhs) {
    if (this != &rhs) {
        this->_stack = rhs.getStack();
    }
    return *this;
}

/******************************************************************************
 * ToString * ToString * ToString * ToString * ToString * ToString * ToString *
 ******************************************************************************/

/*************************************************************************
 * Other * Other * Other * Other * Other * Other * Other * Other * Other *
 *************************************************************************/
void AbstractStack::push(IOperand *value) {
    this->_stack.push(value);
}

void AbstractStack::pop(){
    if (this->_stack.empty())
        throw EmptyStackException();
    else
        this->_stack.pop();
}

void AbstractStack::dump() {
    AbstractStack dumpedStack = AbstractStack(*this);
    std::stringstream ss;

    while (!dumpedStack.getStack().empty()){
        ss << dumpedStack.getStack().top()->getValue() << std::cout;
        dumpedStack.getStack().pop();
    }

    std::cout << ss.str();
}

void AbstractStack::assert(IOperand *value) const{
    if (this->_stack.empty())
        throw EmptyStackException();
    else if (!(*(this->_stack.top()) == *value))
        throw AssertFailException();
}

void AbstractStack::add(){
    if (this->_stack.size() < 2)
        throw StackTooShortException();
    else {
        IOperand a = this->_stack.top();
        this->_stack.pop();
        IOperand b = this->_stack.top();
        this->_stack.pop();

        push(a + b);
    }
}

void AbstractStack::sub(){
    if (this->_stack.size() < 2)
        throw StackTooShortException();
    else {
        IOperand a = this->_stack.top();
        this->_stack.pop();
        IOperand b = this->_stack.top();
        this->_stack.pop();

        push(a - b);
    }
}

void AbstractStack::mul(){
    if (this->_stack.size() < 2)
        throw StackTooShortException();
    else {
        IOperand a = this->_stack.top();
        this->_stack.pop();
        IOperand b = this->_stack.top();
        this->_stack.pop();

        push(a * b);
    }
}

void AbstractStack::div(){
    if (this->_stack.size() < 2)
        throw StackTooShortException();
    else {
        IOperand a = this->_stack.top();
        this->_stack.pop();
        IOperand b = this->_stack.top();
        this->_stack.pop();
        if (!b.getValue()){
            push(b);
            push(a);
            throw DivByZeroException();
        }
        else
            push(a / b);
    }
}

void AbstractStack::mod(){
    if (this->_stack.size() < 2)
        throw StackTooShortException();
    else {
        IOperand a = this->_stack.top();
        this->_stack.pop();
        IOperand b = this->_stack.top();
        this->_stack.pop();
        if (!b.getValue()){
            push(b);
            push(a);
            throw DivByZeroException();
        }
        else if (a.getPrecision() > 2 || b.getPrecision() > 2){
            push(b);
            push(a);
            throw ModOnFloatException();
        }
        else
            push(a % b);
    }
}

void AbstractStack::print() const{
    if (this->_stack.empty())
        throw EmptyStackException();
    else {
        IOperand * myChar = this->_stack.top();
        if (myChar->getType() != eOperandType::Int8)
            throw NotPrintableException();
        else
            std::cout << atoi(myChar.getValue()) << std::endl;
    }
}
