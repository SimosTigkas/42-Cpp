/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:12:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/22 16:28:04 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    FragTrap Venom("Venom");
    FragTrap Carnage("Carnage");

    Venom.setAttackDamage(3);
    Venom.attack("Carnage");
    Carnage.takeDamage(3);

    Carnage.setAttackDamage(5);
    Carnage.attack("Venom");
    Venom.takeDamage(5);
    
    Venom.setAttackDamage(6);
    Venom.attack("Carnage");
    Carnage.takeDamage(6);
    
    Carnage.setAttackDamage(5);
    Carnage.attack("Venom");
    Venom.takeDamage(5);
    
    Venom.beRepaired(8);
    Venom.setAttackDamage(5);
    Venom.attack("Carnage");
    Carnage.takeDamage(5);

    Venom.highFivesGuys();
    Carnage.highFivesGuys();

    std::cout << "\U0001F64F High five was successfully done!!\U0001F64F" << std::endl;
    std::cout << std::endl;
    return (0);
}