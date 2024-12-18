/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:50 by stigkas           #+#    #+#             */
/*   Updated: 2024/12/18 11:32:20 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main(void) 
{
    ShrubberyCreationForm blueberry("mustikka");
    Bureaucrat Anton("Anton", 35);
    std::cout << Anton << std::endl;
    Bureaucrat Antti("Antti", 1);
    std::cout << Antti << "\n" << std::endl;

    Anton.signForm(blueberry);
    Anton.executeForm(blueberry);
    Antti.signForm(blueberry);
    Antti.executeForm(blueberry);
    std::cout << std::endl;

    PresidentialPardonForm zaphodPardon("Ville");
    Anton.signForm(zaphodPardon);
    Anton.executeForm(zaphodPardon);
    Antti.signForm(zaphodPardon);
    Antti.executeForm(zaphodPardon);
    std::cout << std::endl;

    RobotomyRequestForm drill("driller");
    Anton.signForm(drill);
    Anton.executeForm(drill);
    Antti.signForm(drill);
    Antti.executeForm(drill);
    Anton = Antti;
    Anton.executeForm(drill);

    std::cout << std::endl;
    return 0;
}
