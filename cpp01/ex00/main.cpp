/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:18:32 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/24 12:18:32 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string input = "";
    Zombie      *new_zombie;

    std::cout << "Let's create a zombie on the heap: " << std::endl;
    std::cout << "Give a name to the zombie: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
    {
        std::cin.clear();
        clearerr(stdin);
    }
    new_zombie = newZombie(input);
    new_zombie->announce();
    delete new_zombie;

    std::cout << "\nLet's create a zombie on the stack:" << std::endl;
    std::cout << "Give a name to the zombie: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
    {
        std::cin.clear();
        clearerr(stdin);
    }
    randomChump(input);
    return (0);
}
