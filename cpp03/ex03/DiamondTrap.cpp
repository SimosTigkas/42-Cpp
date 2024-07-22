/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:30 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/22 14:43:54 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
    this->name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap " << name << "constructor is called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &a_copy): ScavTrap(a_copy), FragTrap(a_copy), ClapTrap(a_copy)
{
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

