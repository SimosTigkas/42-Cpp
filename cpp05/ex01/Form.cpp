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

Form::Form(std::string name, unsigned int sGrade, unsigned int eGrade): name(name), sGrade(sGrade), eGrade(eGrade)
{
    std::cout << "Form " << this->name <<" (with signing grade: " << sGrade << " and execution grade: "<< eGrade << ") has been created" << std::endl;
    if (sGrade > 150 || eGrade > 150)
        throw Form::GradeTooLowException();
    else if (sGrade < 1 || eGrade < 1)
        throw Form::GradeTooHighException();
}