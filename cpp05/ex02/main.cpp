/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:50 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/29 14:00:17 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main(void) 
{
    ShrubberyCreationForm blueberry("mustikka");
    Bureaucrat Anton;
    Bureaucrat Antti("Antti", 1);

    Anton.signForm(blueberry);
    Anton.executeForm(blueberry);
    Antti.signForm(blueberry);
    Antti.executeForm(blueberry);

    PresidentialPardonForm zaphodPardon("Zaphod");
    Anton.signForm(zaphodPardon);
    Anton.executeForm(zaphodPardon);
    Antti.signForm(zaphodPardon);
    Antti.executeForm(zaphodPardon);

    RobotomyRequestForm drill("driller");
    Anton.signForm(drill);
    Anton.executeForm(drill);
    Antti.signForm(drill);
    Antti.executeForm(drill);
    Anton = Antti;
    Anton.executeForm(drill);

    return 0;
}
