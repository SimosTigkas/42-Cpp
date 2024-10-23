/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:39 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/23 17:34:29 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{   
    try
	{
		Bureaucrat Antti("Antti", 42);
		std::cout << Antti << std::endl;
		Bureaucrat Tomi("Tomi", 24);
		std::cout << Tomi << std::endl;
		std::cout << "Original: " << Antti << std::endl;
		Antti = Tomi;
		std::cout << "After:    " << Antti << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}
    
    try
	{
		Bureaucrat Antti("Antti", 150);
		Antti.decrementGrade();
	}
	catch(const Bureaucrat::GradeTooLowException& e)
    {
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
    }

    try
	{
		Bureaucrat Antti("Antti", 1);
		std::cout << Antti << std::endl;
		Antti.decrementGrade();
		std::cout << Antti << std::endl;
		Antti.incrementGrade();
		std::cout << Antti << std::endl;
		Bureaucrat Sofia("Sofia", 70);
		std::cout << Sofia << std::endl;
		Sofia.incrementGrade();
		std::cout << Sofia << std::endl;
		Sofia.decrementGrade();
		std::cout << Sofia << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}
	return (0);
}
