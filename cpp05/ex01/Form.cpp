/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:55:49 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/23 17:55:49 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): name("No name"), isSigned(false), sGrade(1), eGrade(1)
{
    std::cout << "Form of " << this->name <<"'s (with signing grade: " << sGrade << " and execution grade: "<< eGrade << ") Default Constructor has been called." << std::endl;
}

Form::~Form(void)
{
    std::cout << "Form of " << this->name <<" (with signing grade: " << sGrade << " and execution grade: "<< eGrade << ") has been destroyed" << std::endl;
}

Form::Form(std::string name, unsigned int sGrade, unsigned int eGrade): name(name), sGrade(sGrade), eGrade(eGrade)
{
    std::cout << "Form of " << this->name <<" (with signing grade: " << sGrade << " and execution grade: "<< eGrade << ") has been created" << std::endl;
    if (sGrade > 150 || eGrade > 150)
        throw Form::GradeTooLowException();
    else if (sGrade < 1 || eGrade < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form &a_copy): name(a_copy.name),  isSigned(a_copy.isSigned), sGrade(a_copy.sGrade), eGrade(a_copy.eGrade)
{
    std::cout << "Form of " << name <<"'s (with signing grade: " << sGrade << " and execution grade: "<< eGrade << ") Copy Constructor has been called." << std::endl;
}

Form &Form::operator=(const Form &og)
{
    std::cout << "Form assignment operator has been called." << std::endl;
    if (this != &og)
    {
        // this->name = og.name;
        // this->sGrade = og.sGrade;
        // this->eGrade = og.eGrade;
        this->isSigned = og.isSigned;
        return (*this);
    }
    return (*this);
}

const char *Form::GradeTooLowException::what() const throw()
{
	const char *error = "The grade is too low. The minimum grade is 150.";
	return error;
}

const char *Form::GradeTooHighException::what() const throw()
{
	const char *error = "The grade is too high. The maximum grade is 1.";
	return error;
}

std::string Form::getName(void) const
{
    return this->name;
}

int Form::getSGrade(void) const
{
    return this->sGrade;
}

int Form::getEGrade(void) const
{
    return this->eGrade;
}

bool Form::getIsSigned(void) const
{
    return this->isSigned;
}

std::ostream &operator<<(std::ostream &out, const Form &og)
{
    std::cout << "Form overload-insertion operator has been called." << std::endl;
	out << "Form: " << og.getName() << "\nIs it signed? " << og.getIsSigned() << "\nSigning grade: " << og.getSGrade() << "\nExecution Grade: " << og.getEGrade() << ".\n";
    return (out);
}

bool Form::beSigned(const Bureaucrat &bur)
{
    std::cout << bur.getName() << " is trying to sign the form " << this->getName() << std::endl;
    int signing_grade = bur.getGrade();

    if (signing_grade > this->sGrade)
        throw Form::GradeTooLowException();
    if (this->isSigned)
    {
        std::cout << bur.getName() << "cannot sign the form " << this->getName() << " since it's already signed" << std::endl;
        return false;
    }
    this->isSigned = true;
    std::cout << "The form " << this->getName() << "is now signed by " << bur.getName() << std::endl;
    return (this->isSigned); 
}

