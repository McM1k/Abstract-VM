/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:23:57 by gboudrie          #+#    #+#             */
/*   Updated: 2018/02/02 14:23:57 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_TPP
# define OPERAND_TPP

# include "IOperand.hpp"
# include "eOperandType.hpp"
# include "OperandFactory.hpp"
# include "../exceptions/OperandExceptions.epp"
# include <iostream>
# include <sstream>

template <typename T>
class Operand : public IOperand {
public:
/****************************************************************************
 * Constructors * Constructors * Constructors * Constructors * Constructors *
 ****************************************************************************/
	Operand(T value, eOperandType type) :
			_type(type),// may not compile
			_precision(static_cast<int>(type)) //cast could nest compiling errors
			{
				this->_value = value;
	}

	Operand(T const & src) :
			_type(src.getType()),
			_precision(src.getPrecision())
			{
				*this = src;
	}

/***********************************************************************
 * Destructors * Destructors * Destructors * Destructors * Destructors *
 ***********************************************************************/
	virtual ~Operand() = default;

/***********************************************************************
 * Getters * Getters * Getters * Getters * Getters * Getters * Getters *
 ***********************************************************************/

	int				getPrecision( void ) const{
		return this->_precision;
	} // Precision of the type of the instance

	eOperandType	getType( void ) const{
		return this->_type;
	} // Type of the instance

/***********************************************************************
 * Setters * Setters * Setters * Setters * Setters * Setters * Setters *
 ***********************************************************************/

/*************************************************************************
 * Operators * Operators * Operators * Operators * Operators * Operators *
 *************************************************************************/
	IOperand &operator=(Operand<T> const &rhs){
		if (this != &rhs) {
			this->_value = rhs.getValue();
		}
		return *this;
	}

    bool operator==(Operand<T> const &rhs){
        if (this->_value == rhs.getValue())
            return true;
        return false;
    }

/******************************************************************************
 * ToString * ToString * ToString * ToString * ToString * ToString * ToString *
 ******************************************************************************/
	std::string const & toString( void ) const{
		std::stringstream ss;
		std::string str;
		ss << this->_value;
		str = ss.str();
		return str;
	} // String representation of the instance

/*************************************************************************
 * Other * Other * Other * Other * Other * Other * Other * Other * Other *
 *************************************************************************/
	IOperand const * operator+( IOperand const & rhs ) const{
		long double result = this->_value + std::stold(rhs.toString());
		eOperandType resultType;

        if (this->getPrecision() >= rhs.getPrecision()){
			resultType = this->getType();
        } else {
			resultType = rhs.getType();
        }
		return _factory.createOperand(resultType, result.str());
	}

	IOperand const * operator-( IOperand const & rhs ) const{
		long double result = this->_value - std::stold(rhs.toString());
		eOperandType resultType;

		if (this->getPrecision() >= rhs.getPrecision()){
			resultType = this->getType();
		} else {
			resultType = rhs.getType();
		}
		return _factory.createOperand(resultType, result.str());
	}

	IOperand const * operator*( IOperand const & rhs ) const{
		long double result = this->_value * std::stold(rhs.toString());
		eOperandType resultType;

		if (this->getPrecision() >= rhs.getPrecision()){
			resultType = this->getType();
		} else {
			resultType = rhs.getType();
		}
		return _factory.createOperand(resultType, result.str());
	}

	IOperand const * operator/( IOperand const & rhs ) const{
		long double a = this->_value;
		long double b = std::stold(rhs.toString());
		if (b == 0)
			throw DivideByZeroException();

		long double result = a / b;
		eOperandType resultType;

		if (this->getPrecision() >= rhs.getPrecision()){
			resultType = this->getType();
		} else {
			resultType = rhs.getType();
		}
		return _factory.createOperand(resultType, result.str());
	}

	IOperand const * operator%( IOperand const & rhs ) const{
		if (this->getType() > eOperandType::Int32 || rhs.getType() > eOperandType::Int32)
			throw ModOnFloatException();

		long long a = this->_value;
		long long b = std::stoll(rhs.toString());
		if (b == 0)
			throw DivideByZeroException();

		long long result = a % b;
		eOperandType resultType;

		if (this->getPrecision() >= rhs.getPrecision()){
			resultType = this->getType();
		} else {
			resultType = rhs.getType();
		}
		return _factory.createOperand(resultType, result.str());
	}


private:
	int						const 	_precision;
	eOperandType			const 	_type;
	T								_value;
	static OperandFactory			_factory;

	Operand() = default;
};

#endif