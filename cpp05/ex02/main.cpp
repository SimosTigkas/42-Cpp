/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:50 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/19 17:53:58 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main(void) 
{
    ShrubberyCreationForm blueberry("mustikka");
    Bureaucrat* Anton = nullptr;
    Bureaucrat* Antti = nullptr;
    try
    {
        try
        {
            Anton = new Bureaucrat("Anton", 35);
            std::cout << *Anton << "\n" << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException& e)
        {
            std::cerr << "\033[31mError creating Anton: " << e.what() << "\033[0m\n";
        }
        catch (const Bureaucrat::GradeTooLowException& e)
        {
            std::cerr << "\033[31mError creating Anton: " << e.what() << "\033[0m\n";
        }
        try
        {
            Antti = new Bureaucrat("Antti", 2);
            std::cout << *Antti << "\n" << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException& e)
        {
            std::cerr << "\033[31mError creating Antti: " << e.what() << "\033[0m\n";
        }
        catch (const Bureaucrat::GradeTooLowException& e)
        {
            std::cerr << "\033[31mError creating Antti: " << e.what() << "\033[0m\n";
        }

        if (Anton && Antti)
        {
            Anton->signForm(blueberry);
            Anton->executeForm(blueberry);
            Antti->signForm(blueberry);
            Antti->executeForm(blueberry);

            PresidentialPardonForm zaphodPardon("Ville");
            Anton->signForm(zaphodPardon);
            Anton->executeForm(zaphodPardon);
            Antti->signForm(zaphodPardon);
            Antti->executeForm(zaphodPardon);

            RobotomyRequestForm drill("driller");
            Anton->signForm(drill);
            Anton->executeForm(drill);
            Antti->signForm(drill);
            Antti->executeForm(drill);
            *Anton = *Antti;
            Anton->executeForm(drill);
        }
        delete Anton;
        delete Antti;
    }
    catch(const AForm::GradeTooHighException& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}
    return 0;
}
