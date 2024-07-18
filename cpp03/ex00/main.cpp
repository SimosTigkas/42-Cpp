/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:12:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/18 12:32:19 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Thor("Thor");
    ClapTrap Thanos("Thanos");

    Thor.setAttackDamage(3);
    Thor.attack("Thanos");
    Thanos.takeDamage(3);

    Thanos.setAttackDamage(5);
    Thanos.attack("Thor");
    Thor.takeDamage(5);
    
    Thor.setAttackDamage(6);
    Thor.attack("Thanos");
    Thanos.takeDamage(6);
    
    Thanos.setAttackDamage(5);
    Thanos.attack("Thor");
    Thor.takeDamage(5);
    
    Thor.beRepaired(8);
    Thor.setAttackDamage(5);
    Thor.attack("Thanos");
    Thanos.takeDamage(5);
    return (0);
}