/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:12:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/16 12:17:14 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap Zeus("Zeus");
    DiamondTrap Poseidon("Poseidon");

    Zeus.whoAmI();
    Poseidon.whoAmI();
    Zeus.attack("Poseidon");
    Zeus.guardGate();
    Zeus.highFivesGuys();
    Poseidon.takeDamage(30);
    Poseidon.beRepaired(35);
    Poseidon.attack("Zeus");
    Poseidon.guardGate();
    Poseidon.highFivesGuys();
    Zeus.takeDamage(30);

    return (0);
}