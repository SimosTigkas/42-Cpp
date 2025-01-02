/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:39 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/19 16:54:14 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\033[31m                        ...INVALID GRADES...\033[0m" << std::endl;
	Bureaucrat* Antti = nullptr;
	try
	{
		Form form("Camera renting permit", 0, 70);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}

	try
	{
		Form form("Camera renting permit", 150, 151);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}

	try
	{
		Form cameraRenting("Camera Renting Permit", 1, 150);
		std::cout << cameraRenting << std::endl;
		Form gearRenting("Gear Renting Permit", 70, 150);
		std::cout << gearRenting << std::endl;
		std::cout << "Original: \n" << cameraRenting << std::endl;
		try
		{
			Antti = new Bureaucrat("Antti", 22);
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
		}
		if (Antti)
		{
			gearRenting.beSigned(*Antti);
    	}
		cameraRenting = gearRenting;
		std::cout << "After: \n" << cameraRenting << std::endl;
        delete Antti;
        Antti = nullptr;
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}

	try
	{
		Form form("Camera renting", 30, 35);
		std::cout << form << std::endl;
		try
		{
			Antti = new Bureaucrat("Antti", 70);
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
		}
		if (Antti)
    	{
			Antti->signForm(form);
        	delete Antti;
        	Antti = nullptr;
    	}
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}

	std::cout << "\n\033[34m                         ...VALID GRADES...\033[0m" << std::endl;
	try
	{
		Form cameraRenting("Camera Renting Permit", 1, 150);
		std::cout << cameraRenting << std::endl;
		try
		{
			Antti = new Bureaucrat("Antti", 1);
		}
		catch(const Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
		}
		if (Antti)
		{
			Antti->signForm(cameraRenting);
			std::cout << cameraRenting << std::endl;
			Form gearRenting("Gear Renting Permit", 70, 150);
			std::cout << gearRenting << std::endl;
			if (!gearRenting.beSigned(*Antti))
				std::cerr << "FAIL" << std::endl;
			std::cout << gearRenting << std::endl;
		}
		delete Antti;
	    Antti = nullptr;
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "\033[31mFAIL: " << e.what() << "\033[0m" << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "\033[31mFAIL: " << e.what() << "\033[0m" << std::endl;
	}
	return (0);
}
