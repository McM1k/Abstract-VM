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

#include "AbstractStack.hpp"
#include <iostream>

/****************************************************************************
 * Constructors * Constructors * Constructors * Constructors * Constructors *
 ****************************************************************************/
AbstractStack::AbstractStack(void) {
    this->_stack = new std::stack<IOperand*>();
}

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
std::stack AbstractStack::getStack() const {
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

void AbstractStack::pop() throw(EmptyStackException){
    if (this->_stack.empty())
        throw EmptyStackException;
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

void AbstractStack::assert(IOperand *value) const throw(EmptyStackException, AssertFailException){
    if (this->_stack.empty())
        throw EmptyStackException;
    else if (!(*(this->_stack.top()) == *value))
        throw AssertFailException;
}

void AbstractStack::add() throw(StackTooShortException) {
    if (this->_stack.size() < 2)
        throw StackTooShortException;
    else {
        IOperand a = this->_stack.top();
        this->_stack.pop();
        IOperand b = this->_stack.top();
        this->_stack.pop();

        push(a + b);
    }
}

void AbstractStack::sub() throw(StackTooShortException){
    if (this->_stack.size() < 2)
        throw StackTooShortException;
    else {
        IOperand a = this->_stack.top();
        this->_stack.pop();
        IOperand b = this->_stack.top();
        this->_stack.pop();

        push(a - b);
    }
}

void AbstractStack::mul() throw(StackTooShortException){
    if (this->_stack.size() < 2)
        throw StackTooShortException;
    else {
        IOperand a = this->_stack.top();
        this->_stack.pop();
        IOperand b = this->_stack.top();
        this->_stack.pop();

        push(a * b);
    }
}

void AbstractStack::div() throw(StackTooShortException, DivByZeroException){
    if (this->_stack.size() < 2)
        throw StackTooShortException;
    else {
        IOperand a = this->_stack.top();
        this->_stack.pop();
        IOperand b = this->_stack.top();
        this->_stack.pop();
        if (!b.getValue()){
            push(b);
            push(a);
            throw (DivByZeroException);
        }
        else
            push(a / b);
    }
}

void AbstractStack::mod() throw(StackTooShortException, DivByZeroException, ModOnFloatException){
    if (this->_stack.size() < 2)
        throw StackTooShortException;
    else {
        IOperand a = this->_stack.top();
        this->_stack.pop();
        IOperand b = this->_stack.top();
        this->_stack.pop();
        if (!b.getValue()){
            push(b);
            push(a);
            throw (DivByZeroException);
        }
        else if (a.getPrecision() > 2 || b.getPrecision() > 2){
            push(b);
            push(a);
            throw (ModOnFloatException);
        }
        else
            push(a % b);
    }
}

void AbstractStack::print() const throw(EmptyStackException, NotPrintableException){
    if (this->_stack.empty())
        throw EmptyStackException;
    else {
        IOperand * myChar = this->_stack.top();
        if (myChar->getType() != eOperandType::Int8)
            throw (NotPrintableException);
        else
            std::cout << atoi(myChar.getValue()) << std::endl;
    }
}

/*******************************************************************************
 * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions *
 *******************************************************************************/
const char* AbstractStack::EmptyStackException::what() const {
    return "The stack is empty";
}

const char* AbstractStack::AssertFailException::what() const {
    return "The assertion failed";
}

const char* AbstractStack::StackTooShortException::what() const {
    return "The stack needs two elements to proceed to this operation";
}

const char* AbstractStack::DivByZeroException::what() const {
    return "You tried to divide by zero, which is impossible";
}

const char* AbstractStack::NotPrintableException::what() const {
    return "Not an Int8 : cannot print";
}

const char* AbstractStack::ModOnFloatException::what() const {
    return "Can't optain a modulo on an non-euclidian division";
}