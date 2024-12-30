/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:29 by stigkas           #+#    #+#             */
/*   Updated: 2024/12/30 13:50:43 by stigkas          ###   ########.fr       */
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
		std::cout << "\nOriginal: \n" << Antti << std::endl;
		Antti = Tomi;
		std::cout << "\nAfter: \n" << Antti << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl;
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
		std::cout << Sofia << "\n" << std::endl;
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