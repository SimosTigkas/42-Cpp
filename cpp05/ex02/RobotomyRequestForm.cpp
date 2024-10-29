/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:19:44 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/28 15:19:44 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm " << this->target << " Default constructor has been called." <<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string the_target): AForm("RobotomyRequestForm", 72, 45)
{
    target = the_target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a_copy)
{
    this->target = a_copy.target;
    std::cout << "RobotomyRequestForm " << this->target << " Copy Constructor has been called." <<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm " << this->target << " has been destroyed." <<std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &og)
{
    std::cout << "RobotomyRequestForm assignment operator has been called." << std::endl;
    if (this != &og)
    {
        this->target = og.target;
        return (*this);
    }
    return (*this);
}

void    RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    std::string     noise;
    int             randomness;

    noise = "Vrrr...vrr..vr.";
    if (!this->getIsSigned())
        throw FormIsNotSignedException();
    if (executor.getGrade() <= this->getEGrade())
    {
        std::cout << noise << std::endl;
        std::srand(std::time(nullptr));
        randomness = std::rand();
        if (randomness % 2)
            std::cout << target << " has been robotomized successfully!" << std::endl;
        else
            std::cout << target << " 's robotomy failed..." <<std::endl;
    }
    else
        throw GradeTooLowException();
}
