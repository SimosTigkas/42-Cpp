/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:32:06 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/25 21:32:06 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void){}

Harl::~Harl(void){}

void Harl::debug(void)
{
    std::cout << "\nI love having extra bacon"
        << " for my 7XL-double-cheese-triple"
        << "-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "\nI cannot believe adding extra bacon"
        << " costs more money. You didn't put"
        << " enough bacon in my burger! If "
        << "you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "\nI think I deserve to "
        << "have some extra bacon for free. I've "
        << "been coming for years whereas you started "
        << "working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "\nThis is unacceptable! "
        << "I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*options[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i=0;
    while (i < 4)
    {
        if (level == levels[i])
        {
            (this->*(options[i]))();
            return ;
        }
        i++;
    }
    std::cout << "The available comment levels are DEBUG, INFO, WARNING, ERROR!!" << std::endl;
    return;
}