/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:13:12 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/12 12:18:34 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "\nClapTrap " << name << " has been called!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << this->name << " has been destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &a_copy)
{
    this->name = a_copy.name;
    this->attackDamage = a_copy.attackDamage;
    this->energyPoints = a_copy.energyPoints;
    this->hitPoints = a_copy.hitPoints;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &og)
{
    if (this != &og)
    {
        this->name = og.name;
        this->attackDamage = og.attackDamage;
        this->energyPoints = og.energyPoints;
        this->hitPoints = og.hitPoints;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    this->attackDamage = 5;
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " has no energy points left.." << std::endl;
        return ;
    }
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " is dead and cannot attack..." << std::endl;
        return;
    }
    std::cout << "Claptrap " << this->name 
        << " attacks " << target 
        << ",causing " << this->attackDamage 
        << " points of damage!" << std::endl;
    this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
    {
        if (this->hitPoints == 0)
        {
            std::cout << "ClapTrap " << this->name << " is already dead and cannot take more damage..." << std::endl;
            return;
        }

        if (amount >= this->hitPoints)
        {
            std::cout << "ClapTrap " << this->name << " is dead..." << std::endl;
            this->hitPoints = 0;
        }
        else
        {
            this->hitPoints -= amount;
            std::cout << this->name << " took " << amount << " points of damage." << std::endl;
            std::cout << this->name << " has " << this->hitPoints << " hit points left!\n" << std::endl;
        }
    }

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap has no energy points left..." << std::endl;
        return;
    }
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name << " is already dead..cannot be repaired..\n" << std::endl;
        return;
    }
    this->hitPoints += amount;
    this->energyPoints--;
    std::cout << "ClapTrap " << this->name
        << " got " << amount 
        << " hit points back and now has total of " 
        << this->hitPoints << " hit points!!!!!\n" 
        << std::endl;
}
