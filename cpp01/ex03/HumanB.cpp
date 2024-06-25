/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:02:40 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/25 12:48:06 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB()
{
    
}

void HumanB::setWeapon(Weapon& weapon)
{
    if (weapon.getType().empty())
    {
        std::cout << "Type in a non-empty string!!" << std::endl;
        return;
    }
    this->_weapon = &weapon;
}

void HumanB::attack(void) const
{
    if (this->_weapon == NULL || this->_weapon->getType().empty())
	{
		std::cout << "You need a weapon in order to be able to attack." << std::endl;
		return ;
	} 
	std::cout << this->_name << " attacks with their "
		<< this->_weapon->getType() << std::endl;
}