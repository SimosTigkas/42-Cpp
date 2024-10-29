/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:17:12 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/29 20:17:12 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
    std::cout << "Intern Default constructor has been called." << std::endl;
}

Intern::~Intern(void)
{
    std::cout << "Intern Destructor has been called." << std::endl;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string namesOfForms[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
    int i = 0;

    while (i < 3)
    {
        if (formName == namesOfForms[i])
        {
            switch (i)
            {
                case 0:
                    return new ShrubberyCreationForm(target);
                case 1:
                    return new RobotomyRequestForm(target);
                case 2:
                    return new PresidentialPardonForm(target);
            }
        }
        i++;
    }
    return nullptr;
}