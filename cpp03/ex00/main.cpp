/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:12:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/12 12:20:50 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Thor("Thor");
    ClapTrap Thanos("Thanos");

    Thor.attack("Thanos");
    Thanos.takeDamage(5);

    Thanos.beRepaired(5);
    Thanos.attack("Thor");
    Thor.takeDamage(5);

    Thor.attack("Thanos");
    Thanos.takeDamage(5);

    Thanos.attack("Thor");
    Thor.takeDamage(5);

    Thor.attack("Thanos");
    Thanos.takeDamage(5);
    return (0);
}