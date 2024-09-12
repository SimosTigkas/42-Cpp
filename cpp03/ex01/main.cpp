/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:12:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/12 12:27:12 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap Hulk("Hulk");
    ScavTrap Loki("Loki");

    Hulk.attack("Loki");
    Loki.takeDamage(20);

    Loki.attack("Hulk");
    Hulk.takeDamage(20);

    Hulk.attack("Loki");
    Loki.takeDamage(20);
    
    Loki.attack("Hulk");
    Hulk.takeDamage(20);
    
    Hulk.beRepaired(80);
    Hulk.attack("Loki");
    Loki.takeDamage(20);

    Hulk.guardGate();
    Loki.guardGate();
    
    std::cout << std::endl;
    return (0);
}