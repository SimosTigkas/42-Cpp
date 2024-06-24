/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:01:26 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/24 21:59:26 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
{
    this->_name = name;
    this->_weapon = weapon;
}

HumanA::~HumanA(void)
{
    
}

void HumanA::attack() const
{
	if (this->_weapon.getType().empty())
		std::cout << this->_name << " doesn't have a weapon to attack with."
			<< std::endl;
	else
		std::cout << this->_name << " attacks with their "
			<< this->_weapon.getType() << std::endl;
}
