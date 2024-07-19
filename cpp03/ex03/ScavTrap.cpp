/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:14:06 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/19 16:08:15 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " has been called!\n" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->name << " has been destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &a_copy): ClapTrap(a_copy)
{
    std::cout << "\nScavTrap copy constructor has been called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &og)
{
    if (this != &og)
    {
        this->name = og.name;
        this->attackDamage = og.attackDamage;
        this->energyPoints = og.energyPoints;
        this->hitPoints = og.hitPoints;
    }
    std::cout << "Copy assignment constructor has been called!" << std::endl;
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (this->energyPoints == 0)
    {
        std::cout << "ScavTrap " << this->name << " has no energy points left.." << std::endl;
        return ;
    }
    if (this->hitPoints < 1)
        return ;
    std::cout << "ScavTrap " << this->name 
        << " attacks " << target 
        << ",causing " << this->attackDamage 
        << " points of damage!" << std::endl;
    this->energyPoints--;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}
