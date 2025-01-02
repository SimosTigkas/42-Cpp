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
    Bureaucrat* anton = nullptr;
    Bureaucrat* antti = nullptr;
    try
    {
        try
        {
            anton = new Bureaucrat("Anton", 35);
            std::cout << *anton << "\n" << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException& e)
        {
            std::cerr << "\033[31mError creating Anton: " << e.what() << "\033[0m\n";
        }
        catch (const Bureaucrat::GradeTooLowException& e)
        {
            std::cerr << "\033[31mError creating Anton: " << e.what() << "\033[0m\n";
        }
        if (anton)
        {
            anton->signForm(blueberry);
            anton->executeForm(blueberry);
        }

        try
        {
            antti = new Bureaucrat("Antti", 2);
            std::cout << *antti << "\n" << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException& e)
        {
            std::cerr << "\033[31mError creating Antti: " << e.what() << "\033[0m\n";
        }
        catch (const Bureaucrat::GradeTooLowException& e)
        {
            std::cerr << "\033[31mError creating Antti: " << e.what() << "\033[0m\n";
        }
        if (antti)
        {
            antti->signForm(blueberry);
            antti->executeForm(blueberry);
        }
        std::cout << std::endl;
    
        Intern simos;
        AForm *stigkas = nullptr;
        try
        {
            if (anton && antti)
            {
                stigkas = simos.makeForm("RobotomyRequestForm", "drill");
                anton->signForm(*stigkas);
                anton->executeForm(*stigkas);
                antti->signForm(*stigkas);
                antti->executeForm(*stigkas);
                *anton = *antti;
                std::cout << *anton << std::endl;
                anton->executeForm(*stigkas);
            }
        }
        catch (const Bureaucrat::GradeTooHighException& e)
        {
            std::cerr << "\033[31mError creating form: " << e.what() << "\033[0m\n";
        }
        catch (const Bureaucrat::GradeTooLowException& e)
        {
            std::cerr << "\033[31mError creating form: " << e.what() << "\033[0m\n";
        }
    
        std::cout << std::endl;
    
        Intern safa;
        AForm* stuna = nullptr;
        try
        {
            if (anton && antti)
            {
                stuna = safa.makeForm("PresidentialPardonForm", "Zaphod");
                anton->signForm(*stuna);
                anton->executeForm(*stuna);
                antti->signForm(*stuna);
                antti->executeForm(*stuna);
            }
        }
        catch (const Bureaucrat::GradeTooHighException& e)
        {
            std::cerr << "\033[31mError creating form: " << e.what() << "\033[0m\n";
        }
        catch (const Bureaucrat::GradeTooLowException& e)
        {
            std::cerr << "\033[31mError creating form: " << e.what() << "\033[0m\n";
        }
        if (stigkas)
            delete stigkas;
        if (stuna)
            delete stuna;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "\033[31mError creating Antti: " << e.what() << "\033[0m\n";
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "\033[31mError creating Antti: " << e.what() << "\033[0m\n";
    }
    if (anton)
        delete anton;
    if (antti)
        delete antti;    
    std::cout << std::endl;

    return 0;
}
