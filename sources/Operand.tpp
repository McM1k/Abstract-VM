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
# include <iostream>
# include <sstream>

template <typename T>
class Operand : public IOperand {
public:
/*
 * Constructors
 */
	Operand(Operand value, eOperandType type) :
			_type(type),
			_precision(static_cast<int>(type)) //cast could nest compiling errors
			{
				this->_value = value;
	};

	Operand(Operand const & src) :
			_type(src.getType()),
			_precision(src.getPrecision())
			{
				*this = src;
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
 * Setters
 */
	void			setValue(T value){
		this->_value = value;
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
			Operand operand<rhs.getType()>() //TODO : stuff
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
	T				_value;

	Operand(void){};
};

#endif