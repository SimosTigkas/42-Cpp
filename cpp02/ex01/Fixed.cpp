/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:13:38 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/27 16:29:29 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->fixedvalue;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedvalue = raw;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedvalue = num * (1 << Fixed::bits);
}

Fixed::Fixed(const float nmro)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedvalue = roundf(nmro * (1 << Fixed::bits));
}

Fixed::Fixed(void)
{
    this->fixedvalue = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &new_obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = new_obj;
}

Fixed &Fixed::operator=(const Fixed &new_obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &new_obj)
        this->fixedvalue = new_obj.fixedvalue;
    return (*this);
}

std::ostream& operator<<(std::ostream &out, const Fixed &new_obj)
{
    out << new_obj.toFloat();
    return (out);
}

float Fixed::toFloat(void) const
{
    return ((float)this->fixedvalue / (float)(1 << Fixed::bits));
}

int Fixed::toInt(void) const
{
    return this->fixedvalue >> Fixed::bits;
}