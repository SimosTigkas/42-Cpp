/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:16:48 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/28 15:16:48 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm " << this->target << " Default constructor has been called." <<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string the_target): AForm("ShrubberyCreationForm", 145, 137)
{
    target = the_target;
    std::cout << "ShrubberyCreationForm " << target << " has been created." <<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a_copy): AForm(a_copy)
{
    this->target = a_copy.target;
    std::cout << "ShrubberyCreationForm " << this->target << " Copy Constructor has been called." <<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm " << this->target << " has been destroyed." <<std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &og)
{
    std::cout << "ShrubberyCreationForm assignment operator has been called." << std::endl;
    if (this != &og)
    {
        this->target = og.target;
        return (*this);
    }
    return (*this);
}

void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    std::string     tree;
    std::ofstream   msg;

    tree = "  #  \n ### \n#####\n  |  \n*****\n";
    if (!this->getIsSigned())
        throw FormIsNotSignedException();
    if (executor.getGrade() <= this->getEGrade())
    {
        msg.open(target + "_shrubbery");
        if (msg.is_open())
        {
            msg << tree;
            msg.close();
        }
    }
    else
        throw GradeTooLowException();
}
