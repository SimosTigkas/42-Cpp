/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:12:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/19 14:48:20 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap Hulk("Hulk");
    ScavTrap Loki("Loki");

    Hulk.setAttackDamage(3);
    Hulk.attack("Loki");
    Loki.takeDamage(3);

    Loki.setAttackDamage(5);
    Loki.attack("Hulk");
    Hulk.takeDamage(5);
    
    Hulk.setAttackDamage(6);
    Hulk.attack("Loki");
    Loki.takeDamage(6);
    
    Loki.setAttackDamage(5);
    Loki.attack("Hulk");
    Hulk.takeDamage(5);
    
    Hulk.beRepaired(8);
    Hulk.setAttackDamage(5);
    Hulk.attack("Loki");
    Loki.takeDamage(5);

    Hulk.guardGate();
    Loki.guardGate();
    
    std::cout << std::endl;
    return (0);
}