/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:12:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/16 11:35:01 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap Hulk("Hulk");
    ScavTrap Loki("Loki");

    Hulk.attack("Loki");
    Hulk.guardGate();
    Loki.takeDamage(20);

    Loki.attack("Hulk");
    Loki.guardGate();
    Hulk.takeDamage(20);

    Hulk.attack("Loki");
    Hulk.guardGate();
    Loki.takeDamage(20);

    Loki.attack("Hulk");
    Loki.guardGate();
    Hulk.takeDamage(20);
    
    Hulk.beRepaired(80);
    Hulk.attack("Loki");
    Hulk.guardGate();
    Loki.takeDamage(20);

    std::cout << std::endl;
    return (0);
}