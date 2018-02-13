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
#include <iostream>

/*
 * Constructors
 */
OperandFactory::OperandFactory(void) {
	OperandFactory::_creator = std::array<void*, 5>();
	_creator.at(eOperandType::Int8) = &(OperandFactory::createInt8());
	_creator.at(eOperandType::Int16) = &(OperandFactory::createInt16());
	_creator.at(eOperandType::Int32) = &(OperandFactory::createInt32());
	_creator.at(eOperandType::Float) = &(OperandFactory::createFloat());
	_creator.at(eOperandType::Double) = &(OperandFactory::createDouble());

}

OperandFactory::OperandFactory(OperandFactory const &src) {
	*this = src;
}// UNUSED

/*
 * Destructors
 */
OperandFactory::~OperandFactory(void) {
}

/*
 * Getters
 */

/*
 * Setters
 */

/*
 * Equals
 */
OperandFactory &OperandFactory::operator=(OperandFactory const &rhs) {
	if (this != &rhs) {
	}
	return *this;
}// UNUSED

/*
 * ToString
 */

/*
 * Other
 */
IOperand const* OperandFactory::createInt8(const std::string &value) const throw(Operand::OverFlowException, Operand::UnderFlowException){
	char min = std::numeric_limits<char>::min(), max = std::numeric_limits<char>::max();
	long long tmpValue = std::stoi(value, nullptr);
	if (tmpValue < min)
		throw (Operand::UnderFlowException);
	if (tmpValue > max)
		throw (Operand::OverFlowException);
	else {
		IOperand int8<eOperandType::Int8>(static_cast<char>(tmpValue), min, max);
		return int8;
	}
}

IOperand const* OperandFactory::createInt16(const std::string &value) const throw(Operand::OverFlowException, Operand::UnderFlowException){
	short int min = std::numeric_limits<short int>::min(), max = std::numeric_limits<short int>::max();
	long long tmpValue = std::stoi(value, nullptr);
	if (tmpValue < min)
		throw (Operand::UnderFlowException);
	if (tmpValue > max)
		throw (Operand::OverFlowException);
	else {
		IOperand int16<eOperandType::Int16>(static_cast<short int>(tmpValue), min, max);
		return int16;
	}
}

IOperand const* OperandFactory::createInt32(const std::string &value) const throw(Operand::OverFlowException, Operand::UnderFlowException){
	int min = std::numeric_limits<int>::min(), max = std::numeric_limits<int>::max();
	long long tmpValue = std::stoi(value, nullptr);
	if (tmpValue < min)
		throw (Operand::UnderFlowException);
	if (tmpValue > max)
		throw (Operand::OverFlowException);
	else {
		IOperand int32<eOperandType::Int32>(static_cast<int>(tmpValue), min, max);
		return int32;
	}
}

IOperand const* OperandFactory::createFloat(const std::string &value) const throw(Operand::OverFlowException, Operand::UnderFlowException){
	float min = std::numeric_limits<float>::min(), max = std::numeric_limits<float>::max();
	long double tmpValue = std::stod(value, nullptr);
	if (tmpValue < min)
		throw (Operand::UnderFlowException);
	if (tmpValue > max)
		throw (Operand::OverFlowException);
	else {
		IOperand float32<eOperandType::Float>(static_cast<float>(tmpValue), min, max);
		return float32;
	}
}

IOperand const* OperandFactory::createDouble(const std::string &value) const throw(Operand::OverFlowException, Operand::UnderFlowException){
	double min = std::numeric_limits<double>::min(), max = std::numeric_limits<double>::max();
	long double tmpValue = std::stod(value, nullptr);
	if (tmpValue < min)
		throw (Operand::UnderFlowException);
	if (tmpValue > max)
		throw (Operand::OverFlowException);
	else {
		IOperand double64<eOperandType::Int16>(static_cast<double>(tmpValue), min, max);
		return double64;
	}
}

/*
 * Exceptions
 */