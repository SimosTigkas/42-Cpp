/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:48:12 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/26 18:48:12 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->value = 0;
    std::cout << "Default constructor called!!" << std::endl;
}

Fixed::Fixed(const Fixed &value_copy)
{
    *this = value_copy;
    std::cout << "Copy constructor called!!" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &original)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(original.getRawBits());
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}