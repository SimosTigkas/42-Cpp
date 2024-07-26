/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:34:40 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/26 17:32:17 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    this->type = "Defult_Aanimal";
    std::cout << "\nAAnimal " << this->type << " Default Constructor has been called." << std::endl;
}

AAnimal::AAnimal(std::string type): type(type)
{   
    std::cout << "AAnimal " << type << " has been created!!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &a_copy)
{
    this->type = a_copy.type;
    std::cout << "AAnimal " << this->type << "Copy Constructor has been called." << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &og)
{
    std::cout << "AAnimal assignment operator has been called." << std::endl;
    if (this != &og)
    {
        this->type = og.type;
        return (*this);
    }
    return (*this);
}

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal " << this->type << " has been destroyed." << std::endl;
}

std::string AAnimal::getType(void) const
{
    return (this->type);
}
