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

void AbstractStack::dump() { //TODO: stuff (make a copy then print/pop each element)

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
    else {//TODO: stuff

    }
}

void AbstractStack::sub() throw(StackTooShortException){
    if (this->_stack.size() < 2)
        throw StackTooShortException;
    else {//TODO: stuff

    }
}

void AbstractStack::mul() throw(StackTooShortException){
    if (this->_stack.size() < 2)
        throw StackTooShortException;
    else {//TODO: stuff

    }
}

void AbstractStack::div() throw(StackTooShortException, DivByZeroException){
    if (this->_stack.size() < 2)
        throw StackTooShortException;
    else {//TODO: stuff (dont forget the DIV0)

    }
}

void AbstractStack::mod() throw(StackTooShortException, DivByZeroException){
    if (this->_stack.size() < 2)
        throw StackTooShortException;
    else {//TODO: stuff (dont forget the DIV0)

    }
}

void AbstractStack::print() const throw(EmptyStackException, AssertFailException){
//TODO: stuff (maybe create a new assertException like notPrintableException)
}

void AbstractStack::exit() const throw(NoExitInstructionException){
//TODO: stuff (maybe no exception in this one)
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

const char* AbstractStack::NoExitInstructionException::what() const {
    return "AbstractVM didn't recieve the EXIT instruction at the end of the program";
}