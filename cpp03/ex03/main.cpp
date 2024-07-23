/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:12:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/23 07:21:50 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap Zeus("Zeus");

    Zeus.whoAmI();
    Zeus.setAttackDamage(20);
    Zeus.attack("Poseidon");
    Zeus.guardGate();
    Zeus.highFivesGuys();
    Zeus.takeDamage(20);
    Zeus.beRepaired(15);
    Zeus.setAttackDamage(100);
    Zeus.takeDamage(100);
    return (0);
}