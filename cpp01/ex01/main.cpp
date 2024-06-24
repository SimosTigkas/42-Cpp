/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:13:26 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/24 13:45:31 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int         i = 0;
    int         N;
    Zombie      *zombie_group;
    std::string zombie_name;

    std::cout << "How many zombies do you want to create?" << std::endl;
    std::cout << "Insert a number: ";
    if (std::cin >> N)
    {
        std::cin.clear();
        clearerr(stdin);
    }
    else
	{
	    std::cout << "Invalid input! Please enter an integer!\n" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
    while (i < N)
    {
        std::cout << "Give a name to the zombie #" << i << std::endl;
        std::getline(std::cin, zombie_name);
        if (std::cin.eof())
        {
            std::cin.clear();
            clearerr(stdin);
        }
        if (zombie_name.empty())
            break ;
        i++;
    }
    zombie_group = zombieHorde(N, zombie_name);
    i = 0;
    while (i < N)
    {
        zombie_group[i].announce();
        i++;
    }
    delete[] zombie_group;
    return (0);
}
