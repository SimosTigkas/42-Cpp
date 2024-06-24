/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:18:47 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/24 12:18:47 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name)
{

    if (name.empty())
    {
        std::cout << "You did not give a name to the Zombie..please do" << std::endl;
        return;
    }
    Zombie random_chump(name);
    random_chump.announce();
}
