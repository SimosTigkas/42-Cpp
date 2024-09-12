/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:12:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/12 12:39:40 by stigkas          ###   ########.fr       */
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

    Venom.highFivesGuys();
    Carnage.highFivesGuys();

    return (0);
}