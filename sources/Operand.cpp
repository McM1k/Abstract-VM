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

# include "../includes/IOperand.hpp"
# include "../includes/eOperandType.hpp"
# include "../includes/OperandFactory.hpp"
# include "OperandExceptions.cpp"
# include <iostream>
# include <sstream>

template <typename T>
class Operand : public IOperand {
public:
/****************************************************************************
 * Constructors * Constructors * Constructors * Constructors * Constructors *
 ****************************************************************************/
	Operand(T value, eOperandType type) :
			_precision(static_cast<int>(type)), //cast could nest compiling errors
			_type(type),
			_value(value),
			_txtValue(std::to_string(value)) {
	}

	Operand(T const & src) :
			_type(src.getType()),
			_precision(src.getPrecision()),
			_txtValue(src.toString()),
			_value(std::stold(src.toString()))
			{
				//*this = src;
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
			this->_value = std::stold(rhs.toString());
		}
		return *this;
	}

    bool operator==(Operand<T> const &rhs){
        if (this->_value == std::stold(rhs.toString()))
            return true;
        return false;
    }

/******************************************************************************
 * ToString * ToString * ToString * ToString * ToString * ToString * ToString *
 ******************************************************************************/
	std::string const & toString( void ) const{
		return this->_txtValue;
	} // String representation of the instance

/*************************************************************************
 * Other * Other * Other * Other * Other * Other * Other * Other * Other *
 *************************************************************************/
	IOperand const * operator+( IOperand const & rhs ) const{
        long double a = static_cast<long double>(this->_value);
        long double b = std::stold(rhs.toString());

		long double result = a + b;
        eOperandType resultType = chooseType(*this, rhs);
		return this->_factory.createOperand(resultType, std::to_string(result));
	}

	IOperand const * operator-( IOperand const & rhs ) const{
        long double a = static_cast<long double>(this->_value);
        long double b = std::stold(rhs.toString());

		long double result = a - b;
        eOperandType resultType = chooseType(*this, rhs);
		return this->_factory.createOperand(resultType, std::to_string(result));
	}

	IOperand const * operator*( IOperand const & rhs ) const{
        long double a = static_cast<long double>(this->_value);
        long double b = std::stold(rhs.toString());

		long double result = a * b;
        eOperandType resultType = chooseType(*this, rhs);
		return this->_factory.createOperand(resultType, std::to_string(result));
	}

	IOperand const * operator/( IOperand const & rhs ) const{
		long double a = static_cast<long double>(this->_value);
		long double b = std::stold(rhs.toString());
		if (b == 0)
			throw DivideByZeroException();

		long double result = a / b;
        eOperandType resultType = chooseType(*this, rhs);
		return this->_factory.createOperand(resultType, std::to_string(result));
	}

	IOperand const * operator%( IOperand const & rhs ) const{
		if (this->getType() > eOperandType::Int32 || rhs.getType() > eOperandType::Int32)
			throw ModOnFloatException();

		long long a = static_cast<long long>(this->_value);
		long long b = std::stoll(rhs.toString());
		if (b == 0)
			throw DivideByZeroException();

		long long result = a % b;
		eOperandType resultType = chooseType(*this, rhs);
		return this->_factory.createOperand(resultType, std::to_string(result));
	}


private:
	int						const 	_precision;
	eOperandType			const 	_type;
	T								_value;
	std::string				const	_txtValue;
	OperandFactory			const	_factory;

	Operand() = default;
	eOperandType chooseType(IOperand const &a, IOperand const &b) const{
	    eOperandType resultType;

        if (a.getPrecision() >= b.getPrecision()){
            resultType = a.getType();
        } else {
            resultType = b.getType();
        }
        return resultType;
	}
};

#endif