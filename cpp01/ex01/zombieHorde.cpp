/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:19:23 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/24 15:23:49 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    int i=0;

    if (N < 1)
    {
        std::cout << "You havet to create more than one zombies!!" << std::endl;
        return (NULL);
    }
    if (name.empty())
    {
        std::cout << "You did not give a name to the Zombie..please do" << std::endl;
        return (NULL);
    }
    Zombie *zombieGroup = new Zombie[N];
    while (i < N)
    {
        zombieGroup[i].setName(name);
        i++;
    }
    return (zombieGroup);
}
