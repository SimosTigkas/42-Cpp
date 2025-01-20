/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:39:00 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/18 17:39:00 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int ac, char **av)
{
     if (ac != 2)
    {
        std::cout << "Try this: ./RPN <expression>" << std::endl;
        return (1);
    }
    try
    {
        RPN ex(av[1]);
        if (ex.checkExpression(ex.getExpression()))
        {
            int calculation = ex.calculateExpression(ex.getExpression());
            std::cout << calculation << std::endl;
        }
        else
            throw std::runtime_error("Error");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}