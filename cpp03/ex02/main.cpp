/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:12:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/16 12:06:41 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    FragTrap Venom("Venom");
    FragTrap Carnage("Carnage");

    Venom.attack("Carnage");
    Carnage.takeDamage(30);

    Carnage.attack("Venom");
    Venom.takeDamage(30);
    
    Venom.attack("Carnage");
    Carnage.takeDamage(30);

    Carnage.attack("Venom");
    Venom.takeDamage(30);
    
    Venom.beRepaired(80);
    Venom.attack("Carnage");
    Carnage.takeDamage(30);

    Carnage.highFivesGuys();
    Venom.highFivesGuys();
    return (0);
}