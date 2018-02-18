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
/****************************************************************************
 * Constructors * Constructors * Constructors * Constructors * Constructors *
 ****************************************************************************/
	Operand(T value, T min, T max) :
			_type(T),// may not compile
			_precision(static_cast<int>(type)), //cast could nest compiling errors
			_min(min),
			_max(max)
			{
				this->_value = value;
	}

	Operand(T const & src) :
			_type(src.getType()),
			_precision(src.getPrecision()),
			_min(min),
			_max(max)
			{
				*this = src;
	}

/***********************************************************************
 * Destructors * Destructors * Destructors * Destructors * Destructors *
 ***********************************************************************/
	virtual ~T(void){}

/***********************************************************************
 * Getters * Getters * Getters * Getters * Getters * Getters * Getters *
 ***********************************************************************/

	int				getPrecision( void ) const{
		return this->_precision;
	} // Precision of the type of the instance

	eOperandType	getType( void ) const{
		return this->_type;
	} // Type of the instance

	T       		getValue( void ) const{
		return this->_value;
	}

	T				getMin( void ) const{
		return this->_min;
	}

	T				getMax( void ) const{
		return this->_max;
	}

/***********************************************************************
 * Setters * Setters * Setters * Setters * Setters * Setters * Setters *
 ***********************************************************************/
	void			setValue(T value){
		this->_value = value;
	}

/*************************************************************************
 * Operators * Operators * Operators * Operators * Operators * Operators *
 *************************************************************************/
	IOperand &operator=(T const &rhs){
		if (this != &rhs) {
			this->_value = rhs.getValue();
		}
		return *this;
	}

    bool &operator==(T const &rhs){
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
	IOperand const * operator+( IOperand const & rhs ) const throw(OverFlowException, UnderFlowException){
		if (rhs.getPrecision() > this->getPrecision()) {
			if ((this->getValue() + rhs.getValue()) > rhs.getMax())
				throw (OverFlowException);
			else if ((this->getValue() + rhs.getValue()) < rhs.getMin())
				throw (UnderFlowException);
			else
				Operand operand<rhs.getType()>(this->getValue() + rhs.getValue()); //MAY CAST INCORRECTLY AND LOSE PRECISION //TODO: create obj using builder
		} else {
			if ((this->getValue() + rhs.getValue()) > this->_max())
				throw (OverFlowException);
			else if ((this->getValue() + rhs.getValue()) < this->_min())
				throw (UnderFlowException);
			else
				Operand operand<this->getType()>(this->getValue() + rhs.getValue()); //MAY CAST INCORRECTLY AND LOSE PRECISION
		}
	}

	IOperand const * operator-( IOperand const & rhs ) const throw(OverFlowException, UnderFlowException){
		if (rhs.getPrecision() > this->getPrecision()) {
			if ((this->getValue() + rhs.getValue()) > rhs.getMax())
				throw (OverFlowException);
			else if ((this->getValue() + rhs.getValue()) < rhs.getMin())
				throw (UnderFlowException);
			else
				Operand operand<rhs.getType()>(this->getValue() - rhs.getValue()); //MAY CAST INCORRECTLY AND LOSE PRECISION
		} else {
			if ((this->getValue() + rhs.getValue()) > this->_max())
				throw (OverFlowException);
			else if ((this->getValue() + rhs.getValue()) < this->_min())
				throw (UnderFlowException);
			else
				Operand operand<this->getType()>(this->getValue() - rhs.getValue()); //MAY CAST INCORRECTLY AND LOSE PRECISION
		}
	}

	IOperand const * operator*( IOperand const & rhs ) const throw(OverFlowException, UnderFlowException){
		if (rhs.getPrecision() > this->getPrecision()) {
			if ((this->getValue() + rhs.getValue()) > rhs.getMax())
				throw (OverFlowException);
			else if ((this->getValue() + rhs.getValue()) < rhs.getMin())
				throw (UnderFlowException);
			else
				Operand operand<rhs.getType()>(this->getValue() * rhs.getValue()); //MAY CAST INCORRECTLY AND LOSE PRECISION
		} else {
			if ((this->getValue() + rhs.getValue()) > this->_max())
				throw (OverFlowException);
			else if ((this->getValue() + rhs.getValue()) < this->_min())
				throw (UnderFlowException);
			else
				Operand operand<this->getType()>(this->getValue() * rhs.getValue()); //MAY CAST INCORRECTLY AND LOSE PRECISION
		}
	}

	IOperand const * operator/( IOperand const & rhs ) const throw(OverFlowException, UnderFlowException, DivideByZeroException){
		if (rhs.getValue() == 0)
			throw(DivideByZeroException);
		else {
			if (rhs.getPrecision() > this->getPrecision()) {
				if ((this->getValue() + rhs.getValue()) > rhs.getMax())
					throw (OverFlowException);
				else if ((this->getValue() + rhs.getValue()) < rhs.getMin())
					throw (UnderFlowException);
				else
					Operand operand<rhs.getType()>(this->getValue() / rhs.getValue()); //MAY CAST INCORRECTLY AND LOSE PRECISION
			} else {
				if ((this->getValue() + rhs.getValue()) > this->_max())
					throw (OverFlowException);
				else if ((this->getValue() + rhs.getValue()) < this->_min())
					throw (UnderFlowException);
				else
					Operand operand<this->getType()>(this->getValue() / rhs.getValue()); //MAY CAST INCORRECTLY AND LOSE PRECISION
			}
		}
	}

	IOperand const * operator%( IOperand const & rhs ) const throw(OverFlowException, UnderFlowException, DivideByZeroException) {
		if (rhs.getValue() == 0)
			throw (DivideByZeroException);
		else {
			if (rhs.getPrecision() > this->getPrecision()) {
				if ((this->getValue() + rhs.getValue()) > rhs.getMax())
					throw (OverFlowException);
				else if ((this->getValue() + rhs.getValue()) < rhs.getMin())
					throw (UnderFlowException);
				else
					Operand operand<rhs.getType()>(this->getValue() % rhs.getValue()); //MAY CAST INCORRECTLY AND LOSE PRECISION
			} else {
				if ((this->getValue() + rhs.getValue()) > this->_max())
					throw (OverFlowException);
				else if ((this->getValue() + rhs.getValue()) < this->_min())
					throw (UnderFlowException);
				else
					Operand operand<this->getType()>(this->getValue() % rhs.getValue()); //MAY CAST INCORRECTLY AND LOSE PRECISION
			}
		}
	}

/*******************************************************************************
 * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions *
 *******************************************************************************/
	class OverFlowException : public std::exception {
	public :
		virtual const char *what() const throw(){
			return "Overflowing resulting operand";
		}
	};

	class UnderFlowException : public std::exception {
	public :
		virtual const char *what() const throw(){
			return "Underflowing resulting operand";
		}
	};

	class DivideByZeroException : public std::exception {
	public :
		virtual const char *what() const throw(){
			return "Dividing by zero";
		}
	};

private:
	int				const _precision;
	eOperandType	const _type;
	T				const _min;
	T				const _max;
	T				_value;

	Operand(void){}
};

#endif