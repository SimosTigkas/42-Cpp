/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:50 by stigkas           #+#    #+#             */
/*   Updated: 2024/12/19 12:40:05 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void) 
{
    std::cout << "\n\033[34mLET'S CREATE SOME FORMS!!\n\033[0m" <<std::endl;

    ShrubberyCreationForm blueberry("mustikka");
    Bureaucrat anton("Anton", 7);
    std::cout << anton << std::endl;
    anton.signForm(blueberry);
    anton.executeForm(blueberry);
    Bureaucrat antti("Antti", 1);
    std::cout << antti << std::endl;
    antti.signForm(blueberry);
    antti.executeForm(blueberry);
    
    std::cout << std::endl;
    
    Intern simos;
    AForm* stigkas = simos.makeForm("RobotomyRequestForm", "drill");
    anton.signForm(*stigkas);
    anton.executeForm(*stigkas);
    antti.signForm(*stigkas);
    antti.executeForm(*stigkas);
    anton = antti;
    std::cout << anton << std::endl;
    anton.executeForm(*stigkas);
    
    std::cout << std::endl;
    
    Intern safa;
    AForm* stuna = safa.makeForm("PresidentialPardonForm", "Zaphod");
    anton.signForm(*stuna);
    anton.executeForm(*stuna);
    antti.signForm(*stuna);
    antti.executeForm(*stuna);

    if (stigkas)
        delete stigkas;
    if (stuna)
        delete stuna;
    std::cout << std::endl;

    return 0;
}
