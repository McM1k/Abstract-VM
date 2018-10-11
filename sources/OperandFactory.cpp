/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:25:13 by gboudrie          #+#    #+#             */
/*   Updated: 2018/02/12 18:25:13 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.hpp"
#include "Operand.tpp"
#include <iostream>

/****************************************************************************
 * Constructors * Constructors * Constructors * Constructors * Constructors *
 ****************************************************************************/
OperandFactory::OperandFactory(void) {
	OperandFactory::_creator = std::array<ftAddrCreate , 5>();
	_creator.at(eOperandType::Int8) = &(OperandFactory::createInt8);
	_creator.at(eOperandType::Int16) = &(OperandFactory::createInt16);
	_creator.at(eOperandType::Int32) = &(OperandFactory::createInt32);
	_creator.at(eOperandType::Float) = &(OperandFactory::createFloat);
	_creator.at(eOperandType::Double) = &(OperandFactory::createDouble);

}

OperandFactory::OperandFactory(OperandFactory const &src) {
	*this = src;
}// UNUSED

/***********************************************************************
 * Destructors * Destructors * Destructors * Destructors * Destructors *
 ***********************************************************************/
OperandFactory::~OperandFactory(void) {
}

/***********************************************************************
 * Getters * Getters * Getters * Getters * Getters * Getters * Getters *
 ***********************************************************************/

/***********************************************************************
 * Setters * Setters * Setters * Setters * Setters * Setters * Setters *
 ***********************************************************************/

/*************************************************************************
 * Operators * Operators * Operators * Operators * Operators * Operators *
 *************************************************************************/
OperandFactory &OperandFactory::operator=(OperandFactory const &rhs) {
	if (this != &rhs) {
	}
	return *this;
}// UNUSED

/******************************************************************************
 * ToString * ToString * ToString * ToString * ToString * ToString * ToString *
 ******************************************************************************/

/*************************************************************************
 * Other * Other * Other * Other * Other * Other * Other * Other * Other *
 *************************************************************************/
IOperand const* OperandFactory::createOperand(eOperandType type, const std::string &value) const {
    return this->_creator[type](value);
}

IOperand const* OperandFactory::createInt8(const std::string &value) const throw(Operand::OverFlowException, Operand::UnderFlowException){
	char min = std::numeric_limits<char>::min(), max = std::numeric_limits<char>::max();
	long long tmpValue = std::stoll(value, nullptr);
	if (tmpValue < min)
		throw (Operand::UnderFlowException);
	if (tmpValue > max)
		throw (Operand::OverFlowException);
	else {
		Operand<char> int8(static_cast<char>(tmpValue), min, max, eOperandType::Int8);
		return int8;//TODO explicitly cast into IOperand
	}
}

IOperand const* OperandFactory::createInt16(const std::string &value) const throw(Operand::OverFlowException, Operand::UnderFlowException){
	short int min = std::numeric_limits<short int>::min(), max = std::numeric_limits<short int>::max();
	long long tmpValue = std::stoll(value, nullptr);
	if (tmpValue < min)
		throw (Operand::UnderFlowException);
	if (tmpValue > max)
		throw (Operand::OverFlowException);
	else {
		Operand<short> int16(static_cast<short int>(tmpValue), min, max, eOperandType::Int16);
		return int16;//TODO explicitly cast into IOperand
	}
}

IOperand const* OperandFactory::createInt32(const std::string &value) const throw(Operand::OverFlowException, Operand::UnderFlowException){
	int min = std::numeric_limits<int>::min(), max = std::numeric_limits<int>::max();
	long long tmpValue = std::stoll(value, nullptr);
	if (tmpValue < min)
		throw (Operand::UnderFlowException);
	if (tmpValue > max)
		throw (Operand::OverFlowException);
	else {
		Operand<int> int32(static_cast<int>(tmpValue), min, max, eOperandType::Int32);
		return int32;//TODO explicitly cast into IOperand
	}
}

IOperand const* OperandFactory::createFloat(const std::string &value) const throw(Operand::OverFlowException, Operand::UnderFlowException){
	float min = std::numeric_limits<float>::min(), max = std::numeric_limits<float>::max();
	long double tmpValue = std::stold(value, nullptr);
	if (tmpValue < min)
		throw (Operand::UnderFlowException);
	if (tmpValue > max)
		throw (Operand::OverFlowException);
	else {
		Operand<float> float32(static_cast<float>(tmpValue), min, max, eOperandType::Float);
		return float32;//TODO explicitly cast into IOperand
	}
}

IOperand const* OperandFactory::createDouble(const std::string &value) const throw(Operand::OverFlowException, Operand::UnderFlowException){
	double min = std::numeric_limits<double>::min(), max = std::numeric_limits<double>::max();
	long double tmpValue = std::stold(value, nullptr);
	if (tmpValue < min)
		throw (Operand::UnderFlowException);
	if (tmpValue > max)
		throw (Operand::OverFlowException);
	else {
		Operand<double> double64(static_cast<double>(tmpValue), min, max, eOperandType::Double);
		return double64;//TODO explicitly cast into IOperand
	}
}

/*******************************************************************************
 * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions *
 *******************************************************************************/