/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:27:03 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/25 21:27:03 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl Odin;

    std::cout << "The available comment levels are DEBUG, INFO, WARNING, ERROR!!\n" << std::endl;
    Odin.complain("DEBUG");
    Odin.complain("INFO");
    Odin.complain("WARNING");
    Odin.complain("ERROR");
}