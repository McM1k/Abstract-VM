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

#include "../includes/OperandFactory.hpp"


/****************************************************************************
 * Constructors * Constructors * Constructors * Constructors * Constructors *
 ****************************************************************************/
OperandFactory::OperandFactory(void) {
	_creator[eOperandType::Int8] = &OperandFactory::createInt8;
	_creator[eOperandType::Int16] = &OperandFactory::createInt16;
	_creator[eOperandType::Int32] = &OperandFactory::createInt32;
	_creator[eOperandType::Float] = &OperandFactory::createFloat;
	_creator[eOperandType::Double] = &OperandFactory::createDouble;
}

/***********************************************************************
 * Destructors * Destructors * Destructors * Destructors * Destructors *
 ***********************************************************************/

/***********************************************************************
 * Getters * Getters * Getters * Getters * Getters * Getters * Getters *
 ***********************************************************************/

/***********************************************************************
 * Setters * Setters * Setters * Setters * Setters * Setters * Setters *
 ***********************************************************************/

/*************************************************************************
 * Operators * Operators * Operators * Operators * Operators * Operators *
 *************************************************************************/

/******************************************************************************
 * ToString * ToString * ToString * ToString * ToString * ToString * ToString *
 ******************************************************************************/

/*************************************************************************
 * Other * Other * Other * Other * Other * Other * Other * Other * Other *
 *************************************************************************/
IOperand const* OperandFactory::createOperand(eOperandType type, const std::string &value) const {
    return dynamic_cast<const IOperand *>((this->*_creator[type])(value));
}

IOperand const* OperandFactory::createInt8(const std::string &value) const{
	char min = std::numeric_limits<char>::min(), max = std::numeric_limits<char>::max();
	long long tmpValue = std::stoll(value, nullptr);

	if (tmpValue < min)
		throw UnderFlowException();
	if (tmpValue > max)
		throw OverFlowException();
	else {
		IOperand * int8 = new Operand<char>(static_cast<char>(tmpValue), eOperandType::Int8);
		return int8;
	}
}

IOperand const* OperandFactory::createInt16(const std::string &value) const{
	short int min = std::numeric_limits<short int>::min(), max = std::numeric_limits<short int>::max();
	long long tmpValue = std::stoll(value, nullptr);

	if (tmpValue < min)
		throw UnderFlowException();
	if (tmpValue > max)
		throw OverFlowException();
	else {
		IOperand * int16 = new Operand<short int>(static_cast<short int>(tmpValue), eOperandType::Int16);
		return int16;
	}
}

IOperand const* OperandFactory::createInt32(const std::string &value) const{
	int min = std::numeric_limits<int>::min(), max = std::numeric_limits<int>::max();
	long long tmpValue = std::stoll(value, nullptr);
	if (tmpValue < min)
		throw UnderFlowException();
	if (tmpValue > max)
		throw OverFlowException();
	else {
		IOperand * int32 = new Operand<int>(static_cast<int>(tmpValue), eOperandType::Int32);
		return int32;
	}
}

IOperand const* OperandFactory::createFloat(const std::string &value) const{
	float min = std::numeric_limits<float>::min(), max = std::numeric_limits<float>::max();
	long double tmpValue = std::stold(value, nullptr);
	if (tmpValue < min)
		throw UnderFlowException();
	if (tmpValue > max)
		throw OverFlowException();
	else {
		IOperand * float32 = new Operand<float>(static_cast<float>(tmpValue), eOperandType::Float);
		return float32;
	}
}

IOperand const* OperandFactory::createDouble(const std::string &value) const{
	double min = std::numeric_limits<double>::min(), max = std::numeric_limits<double>::max();
	long double tmpValue = std::stold(value, nullptr);
	if (tmpValue < min)
		throw UnderFlowException();
	if (tmpValue > max)
		throw OverFlowException();
	else {
		IOperand * double64 = new Operand<double>(static_cast<double>(tmpValue), eOperandType::Double);
		return double64;
	}
}

/*******************************************************************************
 * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions *
 *******************************************************************************/