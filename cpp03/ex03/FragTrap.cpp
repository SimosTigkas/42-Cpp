/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:37 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/22 13:50:28 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " has been called!\n" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << this->name << " has been destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &a_copy): ClapTrap(a_copy)
{
    std::cout << "\nFlagTrap copy constructor has been called!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &og)
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

void FragTrap::attack(const std::string& target)
{
    if (this->energyPoints == 0)
    {
        std::cout << "FragTrap " << this->name << " has no energy points left.." << std::endl;
        return ;
    }
    if (this->hitPoints < 1)
        return ;
    std::cout << "FragTrap " << this->name 
        << " attacks " << target 
        << ",causing " << this->attackDamage 
        << " points of damage!" << std::endl;
    this->energyPoints--;
}

void FragTrap::highFivesGuys(void)
{
    if (this->energyPoints < 1)
    {
        std::cout << "FragTrap " << this->name << " is has no energy points left.." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "FragTrap " << this->name << " raises a hand for a High Five: \U0000270B" << std::endl;
}
