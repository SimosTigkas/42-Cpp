/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:02:36 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/15 16:46:00 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): x(0), y(0) {}

Point::~Point(void) {}

Point::Point(const Point &value_copy): x(value_copy.get_x()), y(value_copy.get_y()) {}

Point::Point(const Fixed var1, const Fixed var2): x(var1), y(var2) {}

Point& Point::operator=(const Point &new_obj)
{
    if (this == &new_obj)
        return (*this);
    return (*this);
}

Fixed Point::get_x(void) const
{
    return (this->x);
}

Fixed Point::get_y(void) const
{
    return (this->y);
}