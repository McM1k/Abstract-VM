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
#include "AbstractStackExceptions.cpp"

/****************************************************************************
 * Constructors * Constructors * Constructors * Constructors * Constructors *
 ****************************************************************************/

AbstractStack::AbstractStack(AbstractStack const &src) {
    *this = src;
}

/***********************************************************************
 * Destructors * Destructors * Destructors * Destructors * Destructors *
 ***********************************************************************/
AbstractStack::~AbstractStack() {}

/***********************************************************************
 * Getters * Getters * Getters * Getters * Getters * Getters * Getters *
 ***********************************************************************/
std::stack<IOperand const *> AbstractStack::getStack() const {
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
void AbstractStack::push(IOperand const * value) {
    std::cout << "poulet" <<std::endl;
    this->_stack.push(value);
    std::cout << "braisay" <<std::endl;
}

void AbstractStack::pop(){
    if (this->_stack.empty())
        throw EmptyStackException();
    else {
        delete this->_stack.top();
        this->_stack.pop();
    }
}

void AbstractStack::dump() {
    AbstractStack dumpedStack = AbstractStack(*this);
    std::stringstream ss;

    while (!dumpedStack.getStack().empty()){
        ss << dumpedStack.getStack().top()->toString() << std::endl;
        dumpedStack.getStack().pop();
    }

    std::cout << ss.str();
}

void AbstractStack::assert(IOperand const * value){
    if (this->_stack.empty())
        throw EmptyStackException();
    else if (!(this->_stack.top()->toString() == value->toString()))
        throw AssertFailException();
}

void AbstractStack::add(){
    if (this->_stack.size() < 2)
        throw StackTooShortException();
    else {
        IOperand const * b = this->_stack.top();
        this->_stack.pop();
        IOperand const * a = this->_stack.top();
        this->_stack.pop();

        try {
            push(*a + *b);
        } catch (const OverFlowException& e) {
            std::cerr << e.what() << std::endl;
        } catch (const UnderFlowException& e) {
            std::cerr << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void AbstractStack::sub(){
    if (this->_stack.size() < 2)
        throw StackTooShortException();
    else {
        IOperand const * b = this->_stack.top();
        this->_stack.pop();
        IOperand const * a = this->_stack.top();
        this->_stack.pop();
        try {
            push(*a - *b);
        } catch (const OverFlowException& e) {
            std::cerr << e.what() << std::endl;
        } catch (const UnderFlowException& e) {
            std::cerr << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void AbstractStack::mul(){
    if (this->_stack.size() < 2)
        throw StackTooShortException();
    else {
        IOperand const * b = this->_stack.top();
        this->_stack.pop();
        IOperand const * a = this->_stack.top();
        this->_stack.pop();

        try {
            push(*a * *b);
        } catch (const OverFlowException& e) {
            std::cerr << e.what() << std::endl;
        } catch (const UnderFlowException& e) {
            std::cerr << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void AbstractStack::div(){
    if (this->_stack.size() < 2)
        throw StackTooShortException();
    else {
        IOperand const * b = this->_stack.top();
        this->_stack.pop();
        IOperand const * a = this->_stack.top();
        this->_stack.pop();

        try {
            push(*a / *b);
        } catch (const OverFlowException& e) {
            std::cerr << e.what() << std::endl;
        } catch (const UnderFlowException& e) {
            std::cerr << e.what() << std::endl;
        } catch (const DivideByZeroException& e) {
            std::cerr << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void AbstractStack::mod(){
    if (this->_stack.size() < 2)
        throw StackTooShortException();
    else {
        IOperand const * b = this->_stack.top();
        this->_stack.pop();
        IOperand const * a = this->_stack.top();
        this->_stack.pop();

        try {
            push(*a % *b);
        } catch (const OverFlowException& e) {
            std::cerr << e.what() << std::endl;
        } catch (const UnderFlowException& e) {
            std::cerr << e.what() << std::endl;
        } catch (const DivideByZeroException& e) {
            std::cerr << e.what() << std::endl;
        } catch (const ModOnFloatException& e) {
            std::cerr << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void AbstractStack::print(){
    if (this->_stack.empty())
        throw EmptyStackException();
    else {
        IOperand const * myChar = this->_stack.top();
        if (myChar->getType() != eOperandType::Int8)
            throw NotPrintableException();
        else
            std::cout << static_cast<char>(std::stoi(myChar->toString())) << std::endl;
    }
}
