/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:02:50 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/15 17:23:37 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed ft_abs(Fixed x)
{
    if (x >= 0)
        return (x);
    else
        return (x * (-1));
}

static Fixed area(Point const a, Point const b, Point const c)
{
    return (ft_abs(a.get_x() * (b.get_y() - c.get_y()) + b.get_x() * (c.get_y() - a.get_y()) + c.get_x() * (a.get_y() - b.get_y())) / Fixed(2));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed   abc = area(a, b, c);
    Fixed   pbc = area(point, b, c);
    Fixed   pac = area(point, c, a);
    Fixed   pab = area(point, a, b);

    std::cout << "Sum of the three triangles' areas is: " << pbc + pac + pab << std::endl;
    std::cout << "Original triangle's area is: " << abc << std::endl;
    return (abc == (pbc + pac + pab));
}