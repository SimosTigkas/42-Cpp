/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:12:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/17 18:28:16 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Thor("Thor");
    ClapTrap Thanos("Thanos");
    
    Thor.attack("Thanos");
    Thanos.takeDamage(3);
    Thanos.attack("Thor");
    Thor.takeDamage(5);
    Thor.attack("Thanos");
    Thanos.takeDamage(6);
    Thanos.attack("Thor");
    Thor.takeDamage(5);
    Thor.beRepaired(8);
    Thor.attack("Thanos");
    Thanos.takeDamage(5);
    return (0);
}