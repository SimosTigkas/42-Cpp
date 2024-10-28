/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:11:46 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/28 15:11:46 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): name("No name"), isSigned(false), sGrade(1), eGrade(1)
{
    std::cout << "AForm of " << this->name <<"'s (with signing grade: " << isSigned << " and execution grade: "<< eGrade << ") Default Constructor has been called." << std::endl;
}

AForm::~AForm(void)
{
    std::cout << "AForm of " << this->name <<" (with signing grade: " << sGrade << " and execution grade: "<< eGrade << ") has been destroyed" << std::endl;
}

AForm::AForm(std::string name, unsigned int sGrade, unsigned int eGrade): name(name), isSigned(false), sGrade(sGrade), eGrade(eGrade)
{
    std::cout << "AForm of " << this->name <<" (with signing grade: " << sGrade << " and execution grade: "<< eGrade << ") has been created" << std::endl;
    if (sGrade > 150 || eGrade > 150)
        throw AForm::GradeTooLowException();
    else if (sGrade < 1 || eGrade < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &a_copy): name(a_copy.name),  isSigned(a_copy.isSigned), sGrade(a_copy.sGrade), eGrade(a_copy.eGrade)
{
    std::cout << "AForm of " << name <<"'s (with signing grade: " << sGrade << " and execution grade: "<< eGrade << ") Copy Constructor has been called." << std::endl;
}

AForm &AForm::operator=(const AForm &og)
{
    std::cout << "AForm assignment operator has been called." << std::endl;
    if (this != &og)
    {
        this->isSigned = og.isSigned;
        return (*this);
    }
    return (*this);
}

const char *AForm::GradeTooLowException::what() const throw()
{
	const char *error = "The grade is too low. The minimum grade is 150.";
	return error;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	const char *error = "The grade is too high. The maximum grade is 1.";
	return error;
}

const char *AForm::FormIsNotSignedException::what() const throw()
{
    const char *error = "This form has not been signed yet.";
    return error;
}

std::string AForm::getName(void) const
{
    return this->name;
}

int AForm::getSGrade(void) const
{
    return this->sGrade;
}

int AForm::getEGrade(void) const
{
    return this->eGrade;
}

bool AForm::getIsSigned(void) const
{
    return this->isSigned;
}

std::ostream &operator<<(std::ostream &out, const AForm &og)
{
    std::cout << "AForm overload-insertion operator has been called." << std::endl;
	out << "AForm: " << og.getName() << "\nIs it signed? " << og.getIsSigned() << "\nSigning grade: " << og.getSGrade() << "\nExecution Grade: " << og.getEGrade() << ".\n";
    return (out);
}

bool AForm::beSigned(const Bureaucrat &bur)
{
    std::cout << bur.getName() << " is trying to sign the Aform " << this->getName() << std::endl;
    int signing_grade = bur.getGrade();

    if (signing_grade > this->sGrade)
        throw AForm::GradeTooLowException();
    if (this->isSigned)
    {
        std::cout << bur.getName() << " couldn't sign " << this->getName() << " because it's already signed." << std::endl;
        return false;
    }
    this->isSigned = true;
    std::cout << "The Aform " << this->getName() << "is now signed by " << bur.getName() << std::endl;
    return (this->isSigned); 
}

