/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:30 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/22 16:24:56 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
    this->name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << name << "constructor has been called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &a_copy): ClapTrap(a_copy), ScavTrap(a_copy), FragTrap(a_copy)
{
    *this = a_copy;
	std::cout << "DiamondTrap Copy Constructor has been called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &og)
{
    if (this != &og)
    {
        this->name = og.name + "_clap_trap";
        this->hitPoints = FragTrap::hitPoints;
        this->energyPoints = ScavTrap::energyPoints;
        this->attackDamage = FragTrap::attackDamage;
        return (*this);
    }
    std::cout << "DiamondTrap Copy assignment constructor has been called." << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << this->name << " has been destroyed!" << std::endl;
}

// void ScavTrap::attack(const std::string& target)
// {
//     if (this->energyPoints == 0)
//     {
//         std::cout << "ScavTrap " << this->name << " has no energy points left.." << std::endl;
//         return ;
//     }
//     if (this->hitPoints < 1)
//         return ;
//     std::cout << "ScavTrap " << this->name 
//         << " attacks " << target 
//         << ",causing " << this->attackDamage 
//         << " points of damage!" << std::endl;
//     this->energyPoints--;
// }

void DiamondTrap::whoAmI(void)
{
    std::cout << "I am DiamondTrap " << this->name
    << " and I am coming from the ClapTrap " << ClapTrap::name << "." << std::endl;
}