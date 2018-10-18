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


# include "eOperandType.hpp"
# include "IOperand.hpp"
# include "../exceptions/OperandExceptions.epp"
# include <iostream>
# include <array>
# include <limits>


class OperandFactory {
public:
	OperandFactory();
	virtual ~OperandFactory() = default;

	IOperand const * createOperand( eOperandType type, std::string const & value ) const;

    typedef IOperand const *(OperandFactory::*ftAddrCreate) (std::string const & value) const;

private:

	std::array<ftAddrCreate , 5> _creator;

	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;

	OperandFactory(OperandFactory const &src) = default;
	OperandFactory &operator=(OperandFactory const &rhs) = default; //equals
};

#endif