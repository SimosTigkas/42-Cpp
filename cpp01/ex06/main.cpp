/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:00:50 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/26 13:00:50 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl Odin;

    if (ac != 2)
    {
        std::cout << "\nType in an argument, the available "
            << "comment levels are DEBUG, INFO, WARNING, ERROR!!\n"
            << std::endl;
        return (1);
    }
    Odin.complain(av[1]);
}