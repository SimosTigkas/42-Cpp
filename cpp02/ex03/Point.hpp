/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:02:26 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/28 15:07:57 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point(void);
        ~Point(void);
        Point(Fixed const var1, Fixed const var2);
        Point(const Point &value_copy);
		Point& operator=(const Point &new_obj);
        Fixed get_x(void) const;
		Fixed get_y(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif