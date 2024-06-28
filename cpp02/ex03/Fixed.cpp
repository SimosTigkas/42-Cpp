/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:02:07 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/28 15:40:15 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->fixedvalue = 0;
}

Fixed::~Fixed(void) {}

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
    this->fixedvalue = num * (1 << Fixed::bits);
}

Fixed::Fixed(const float nmro)
{
    this->fixedvalue = roundf(nmro * (1 << Fixed::bits));
}

Fixed::Fixed(const Fixed &new_obj)
{
    *this = new_obj;
}

Fixed &Fixed::operator=(const Fixed &new_obj)
{
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
    return (this->fixedvalue >> Fixed::bits);
}

bool Fixed::operator>(const Fixed &nmro) 
{
	return (this->fixedvalue > nmro.getRawBits());
}

bool Fixed::operator<(const Fixed &nmro) 
{
	return (this->fixedvalue < nmro.getRawBits());
}

bool Fixed::operator<=(const Fixed &nmro) 
{
	return (this->fixedvalue <= nmro.getRawBits());
}

bool Fixed::operator>=(const Fixed &nmro) 
{
	return (this->fixedvalue >= nmro.getRawBits());
}

bool Fixed::operator==(const Fixed &nmro) 
{
	return (this->fixedvalue == nmro.getRawBits());
}

bool Fixed::operator!=(const Fixed &nmro) 
{
	return (this->fixedvalue != nmro.getRawBits());
}

Fixed Fixed::operator+(const Fixed &nmro) 
{
	return (Fixed(this->toFloat() + nmro.toFloat()));
}

Fixed Fixed::operator-(const Fixed &nmro) 
{
	return (Fixed(this->toFloat() - nmro.toFloat()));
}

Fixed Fixed::operator*(const Fixed &nmro) 
{
	return (Fixed (this->toFloat() * nmro.toFloat()));
}

Fixed Fixed::operator/(const Fixed &nmro) 
{
	return (Fixed (this->toFloat() / nmro.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->fixedvalue += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(this->fixedvalue * toFloat());
	this->fixedvalue += 1;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->fixedvalue -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(this->fixedvalue * toFloat());
	this->fixedvalue -= 1;
	return (tmp);
}

Fixed& Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return (obj1);
	return (obj2);
}

const Fixed& Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1.getRawBits() < obj2.getRawBits())
		return (obj1);
	return (obj2);
}

Fixed& Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1.getRawBits() > obj2.getRawBits())
		return (obj1);
	return (obj2);
}

const Fixed& Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1.getRawBits() > obj2.getRawBits())
		return (obj1);
	return (obj2);
}
