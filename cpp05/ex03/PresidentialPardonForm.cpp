/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:21:19 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/28 15:21:19 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm " << this->target << " Default constructor has been called." <<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string the_target): AForm("PresidentialPardonForm", 25, 5)
{
    target = the_target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a_copy): AForm(a_copy)
{
    this->target = a_copy.target;
    std::cout << "PresidentialPardonForm " << this->target << " Copy Constructor has been called." <<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm " << this->target << " has been destroyed." <<std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &og)
{
    std::cout << "PresidentialPardonForm assignment operator has been called." << std::endl;
    if (this != &og)
    {
        this->target = og.target;
        return (*this);
    }
    return (*this);
}

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (!this->getIsSigned())
        throw FormIsNotSignedException();
    if (executor.getGrade() <= this->getEGrade())
        std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    else
        throw GradeTooLowException();
}
