/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:21 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/22 16:01:04 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Animal::Animal(std::string name): type(name)
// {   
//     this->type = "Random_animal";
//     std::cout << "Animal " << this->type << " has been created!!" << std::endl;
// }

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade)
{
    std::cout << "Bureaucrat " << this->name <<" (with grade: " << this->grade << ") has been created" << std::endl;
    //try {
    // //Code that may throw an exception
    // if (some_error_condition) {
    //      throw exception_object;  // Throw an exception
    //  }
    // } 
    // catch (exception_type& e) {
    // Code to handle the exception
    // std::cout << "Error: " << e.what() << std::endl;
    //}
}

Bureaucrat::Bureaucrat(void): name("Antti"), grade(145)
{
    std::cout << "\nBureaucrat " << this->name << " (with grade: " << this->grade << ") Default Constructor has been called." << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat " << this->name << " has been destroyed." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &a_copy)
{
    this->grade = a_copy.grade;
    std::cout << "Bureaucrat " << this->name << " with a grade: " << this->grade << "Copy Constructor has been called." << std::endl;
}


// Bureaucrat &Bureaucrat::operator<<(const Bureaucrat& og)
// {
    
// }