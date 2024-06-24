/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:19:10 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/24 12:56:57 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    
}

Zombie::~Zombie()
{
    std::cout << "Zombie named as " 
        << this->_name << "..DIED.." << std::endl;
}

void Zombie::announce(void)
{
	if (this->_name.empty())
		return ;
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}

const std::string& Zombie::getName(void) const
{
    return (this->_name);
}