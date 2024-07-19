/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:21 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/19 15:59:45 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FlagTrap::FlagTrap(std::string name): ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FlagTrap " << name << " has been called!\n" << std::endl;
}

FlagTrap::~FlagTrap(void)
{
    std::cout << "FlagTrap " << this->name << " has been destroyed!" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap &a_copy): ClapTrap(a_copy)
{
    std::cout << "\nFlagTrap copy constructor has been called!" << std::endl;
}

FlagTrap& FlagTrap::operator=(const FlagTrap &og)
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

void FlagTrap::attack(const std::string& target)
{
    if (this->energyPoints == 0)
    {
        std::cout << "FlagTrap " << this->name << " has no energy points left.." << std::endl;
        return ;
    }
    if (this->hitPoints < 1)
        return ;
    std::cout << "FlagTrap " << this->name 
        << " attacks " << target 
        << ",causing " << this->attackDamage 
        << " points of damage!" << std::endl;
    this->energyPoints--;
}

void FlagTrap::highFivesGuys(void)
{
    if (this->energyPoints < 1)
    {
        std::cout << "FlagTrap " << this->name << " is has no energy points left.." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "FlagTrap " << this->name << " raises a hand for a High Five: \U0000270B" << std::endl;
}