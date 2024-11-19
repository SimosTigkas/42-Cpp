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

Intern::Intern(void)
{
    std::cout << "Intern Default constructor has been called." << std::endl;
}

Intern::~Intern(void)
{
    std::cout << "Intern Destructor has been called." << std::endl;
}

static AForm *createShrubberyForm(const std::string target)
{
	AForm *form;

	try
	{
		form = new ShrubberyCreationForm(target);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Memory allocation failed." << std::endl;
	}

	return form;
}

static AForm *createRobotomyForm(const std::string target)
{
	AForm *form;

	try
	{
		form = new RobotomyRequestForm(target);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Memory allocation failed." << std::endl;
	}

	return form;
}

static AForm *createPresidentalForm(const std::string target)
{
	AForm *form;

	try
	{
		form = new PresidentialPardonForm(target);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Memory allocation failed." << std::endl;
	}
	return form;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    int i=0;
    AForm *form = nullptr;
    if (formName.empty())
        throw AForm::FormDoesNotExist();
    while (i < 3)
    {
        if (!forms[i].compare(formName))
        {    
            switch(i)
            {
                case 0:
                    form = createShrubberyForm(target);
					break ;
                case 1:
                    form = createRobotomyForm(target);
					break ;
                case 2:
                    form = createPresidentalForm(target);
					break ;
            }
        }
        i++;
    }
    if (form != nullptr)
        std::cout << "Intern creates " << formName << std::endl;
    else
        throw AForm::FormDoesNotExist();
    return form;
}