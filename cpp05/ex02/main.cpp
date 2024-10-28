/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:50 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/28 18:03:16 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// int main(void)
// {   
// 	try
// 	{
// 		AForm form("Camera renting permit", 0, 70);
// 	}
// 	catch(const AForm::GradeTooHighException& e)
// 	{
// 		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
// 	}

// 	try
// 	{
// 		AForm form("Camera renting permit", 150, 151);
// 	}
// 	catch(const AForm::GradeTooLowException& e)
// 	{
// 		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
// 	}

// 	try
// 	{
// 		AForm cameraRenting("Camera renting permit", 1, 150);
// 		std::cout << cameraRenting << std::endl;
// 		AForm gearRenting("Gear renting permit", 70, 150);
// 		std::cout << gearRenting << std::endl;
// 		std::cout << "Original: " << cameraRenting << std::endl;
// 		Bureaucrat Antti("Antti", 1);
// 		gearRenting.beSigned(Antti);
// 		cameraRenting = gearRenting;
// 		std::cout << "After: " << cameraRenting << std::endl;
// 	}
// 	catch(const AForm::GradeTooHighException& e)
// 	{
// 		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
// 	}
// 	catch(const AForm::GradeTooLowException& e)
// 	{
// 		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
// 	}

// 	try
// 	{
// 		AForm form("Camera renting", 30, 35);
// 		std::cout << form << std::endl;
// 		Bureaucrat Antti("Antti", 70);
// 		Antti.signForm(form);
// 	}
// 	catch(const AForm::GradeTooLowException& e)
// 	{
// 		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
// 	}

// 	try
// 	{
// 		AForm form("Camera renting", 30, 35);
// 		std::cout << form << std::endl;
// 		Bureaucrat Antti("Antti", 70);
// 		form.beSigned(Antti);
// 	}
// 	catch(const AForm::GradeTooLowException& e)
// 	{
// 		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
// 	}

// 	try
// 	{
// 		AForm cameraRenting("Camera renting permit", 1, 150);
// 		std::cout << cameraRenting << std::endl;
// 		Bureaucrat Antti("Antti", 1);
// 		if (!Antti.signForm(cameraRenting))
// 			std::cerr << "FAIL" << std::endl;
// 		std::cout << cameraRenting << std::endl;
// 		AForm gearRenting("Gear renting permit", 70, 150);
// 		std::cout << gearRenting << std::endl;
// 		if (!gearRenting.beSigned(Antti))
// 			std::cerr << "FAIL" << std::endl;
// 		std::cout << gearRenting << std::endl;
// 	}
// 	catch(const AForm::GradeTooHighException& e)
// 	{
// 		std::cerr << "\033[31mFAIL: " << e.what() << "\033[0m" << std::endl;
// 	}
// 	catch(const AForm::GradeTooLowException& e)
// 	{
// 		std::cerr << "\033[31mFAIL: " << e.what() << "\033[0m" << std::endl;
// 	}
// 	return (0);
// }
