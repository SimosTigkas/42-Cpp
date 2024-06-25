/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:03:23 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/25 12:36:39 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type)
{
    this->_type = type;
}

Weapon::~Weapon(void){}

void Weapon::setType(std::string type)
{
    if (type.empty())
	{
		std::cout << "You typed an empty string. Type a notn empty string this time!!!" << std::endl;
		return ;
	}
    this->_type = type;
}

const std::string& Weapon::getType()
{
    return ((const std::string&)(this->_type));
}