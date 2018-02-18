/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:25:15 by gboudrie          #+#    #+#             */
/*   Updated: 2018/02/12 18:25:15 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDFACTORY_HPP
# define OPERANDFACTORY_HPP
# include "Operand.tpp"
# include <iostream>
# include <array>

typedef IOperand const *(*ftAddrCreate) (std::string const & value);

class OperandFactory {
public:
	OperandFactory(void);
	virtual ~OperandFactory(void);

	IOperand const * createOperand( eOperandType type, std::string const & value ) const;

private:

	std::array _creator;

	IOperand const * createInt8( std::string const & value ) const throw(Operand::OverFlowException, Operand::UnderFlowException);
	IOperand const * createInt16( std::string const & value ) const throw(Operand::OverFlowException, Operand::UnderFlowException);
	IOperand const * createInt32( std::string const & value ) const throw(Operand::OverFlowException, Operand::UnderFlowException);
	IOperand const * createFloat( std::string const & value ) const throw(Operand::OverFlowException, Operand::UnderFlowException);
	IOperand const * createDouble( std::string const & value ) const throw(Operand::OverFlowException, Operand::UnderFlowException);

	OperandFactory(OperandFactory const &src);
	OperandFactory &operator=(OperandFactory const &rhs); //equals
};

#endif