/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:01:40 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/15 17:14:22 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    std::cout << "Let's see if P(10,2) is inside the A(0,0), B(10,30), C(20,0) triangle\n" << std::endl;
    if (bsp(Point(0,0) , Point(10,30), Point(20,0), Point(10,15)) == true)
        std::cout << "The point P(10,15) is inside the ABC triangle.\n" << std::endl;
    else
        std::cout << "The point P(10,15) is not inside the ABC triangle.\n" << std::endl;
    
    std::cout << "Let's see if P(42,15) is inside the A(0,0), B(10,30), C(20,0) triangle\n" << std::endl;
    if (bsp(Point(0,0) , Point(10,30), Point(20,0), Point(42,15)) == true)
        std::cout << "The point P(42,15) is inside the ABC triangle.\n" << std::endl;
    else
        std::cout << "The point P(42,15) is not inside the ABC triangle.\n" << std::endl;
    return (0);
}