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
}

OperandFactory::OperandFactory(OperandFactory const &src) {
	*this = src;
}

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
}

/*
 * ToString
 */

/*
 * Other
 */

/*
 * Exceptions
 */