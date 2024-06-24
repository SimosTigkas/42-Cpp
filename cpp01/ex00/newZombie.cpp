/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:18:38 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/24 12:18:38 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    if (name.empty())
    {
        std::cout << "You did not give a name to the Zombie..please do" << std::endl;
        return (NULL);
    }
    return (new Zombie(name));
}
