/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.tpp                                           :+:      :+:    :+:   */
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
# include <iostream>
# include <sstream>

template <typename T>
class T : public IOperand {
public:
/*
 * Constructors
 */
	T(T value, eOperandType type) :
			_type(type),
			_precision(static_cast<int>(type)), //
			_value(value) {
	};

/*
 * Destructors
 */
	virtual ~T(void){};

/*
 * Getters
 */

	int				getPrecision( void ) const{
		return this->_precision;
	}; // Precision of the type of the instance

	eOperandType	getType( void ) const{
		return this->_type;
	}; // Type of the instance

	T				getValue( void ) const{
		return  this->_value;
	};

/*
 * Equals
 */
	T &operator=(T const &rhs){
		if (this != &rhs) {
			this->_value = rhs.getValue();
		}
		return *this;
	}; //equals

/*
 * ToString
 */
	std::string const & toString( void ) const{
		std::stringstream ss;
		std::string str;
		ss << this->_value;
		str = ss.str();
		return str;
	}; // String representation of the instance

/*
 * Other
 */
	IOperand const * operator+( IOperand const & rhs ) const{
		if (rhs.getPrecision() > this->getPrecision()) {

		}
		else

	};

	IOperand const * operator-( IOperand const & rhs ) const;

	IOperand const * operator*( IOperand const & rhs ) const;

	IOperand const * operator/( IOperand const & rhs ) const;

	IOperand const * operator%( IOperand const & rhs ) const;

/*
 * Exceptions
 */

private:
	int				const _precision;
	eOperandType	const _type;
	T				const _value;

	T(void){};
	T(T const &src) {};

};

#endif