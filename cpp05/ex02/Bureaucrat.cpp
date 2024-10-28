/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:03:45 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/28 15:13:01 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade)
{
    std::cout << "Bureaucrat " << this->name <<" (with grade: " << this->grade << ") has been created" << std::endl;
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
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
    std::cout << "Bureaucrat " << this->name << " with a grade: " << this->grade << " Copy Constructor has been called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &og)
{
    std::cout << "Bureaucrat assignment operator has been called." << std::endl;
    if (this != &og)
    {
        // this->name = og.name;
        this->grade = og.grade;
        return (*this);
    }
    return (*this);
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	const char *error = "The grade is too low. The minimum grade is 150.";
	return error;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	const char *error = "The grade is too high. The maximum grade is 1.";
	return error;
}

unsigned int Bureaucrat::getGrade(void) const
{
    return this->grade;
}

const std::string Bureaucrat::getName(void) const
{
    return this->name;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &og)
{
    std::cout << "Bureaucrat overload-insertion operator has been called." << std::endl;
    out << og.getName() << ", bureaucrat grade " << og.getGrade() << "." ;
    return (out);
}

void Bureaucrat::incrementGrade(void)
{
    if (this->grade > 1)
        this->grade = this->grade - 1;
    else
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(void)
{
    if (this->grade < 150)
        this->grade = this->grade + 1;
    else
        throw Bureaucrat::GradeTooLowException();
}

bool Bureaucrat::signForm(AForm &form) const
{
    try
    {
        if (form.beSigned(*this) == false)
            return false;
    }
    catch(AForm::GradeTooLowException& e)
    {
        std::cout << this->name << " couldn't sign " << form.getName() << " because the signing grade is " << form.getSGrade() << "." << std::endl;
        return false;
    }
    std::cout << this->name << " signed " << form.getName() << "." << std::endl;
    return true;
}

