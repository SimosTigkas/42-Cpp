/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:12:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/12 12:47:06 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap Zeus("Zeus");

    Zeus.whoAmI();
    // Zeus.setAttackDamage(20);
    Zeus.attack("Poseidon");
    Zeus.guardGate();
    Zeus.highFivesGuys();
    Zeus.takeDamage(30);
    Zeus.beRepaired(35);
    // Zeus.setAttackDamage(100);
    Zeus.takeDamage(30);
    return (0);
}