/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:34:40 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/26 17:20:46 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal(void)
{
    this->type = "Defult_Abstractanimal";
    std::cout << "\nAbstractAnimal " << this->type << " Default Constructor has been called." << std::endl;
}

AbstractAnimal::AbstractAnimal(std::string type): type(type)
{   
    std::cout << "AbstractAnimal " << type << " has been created!!" << std::endl;
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal &a_copy)
{
    this->type = a_copy.type;
    std::cout << "AbstractAnimal " << this->type << "Copy Constructor has been called." << std::endl;
}

AbstractAnimal &AbstractAnimal::operator=(const AbstractAnimal &og)
{
    std::cout << "AbstractAnimal assignment operator has been called." << std::endl;
    if (this != &og)
    {
        this->type = og.type;
        return (*this);
    }
    return (*this);
}

AbstractAnimal::~AbstractAnimal(void)
{
    std::cout << "AbstractAnimal " << this->type << " has been destroyed." << std::endl;
}

std::string AbstractAnimal::getType(void) const
{
    return (this->type);
}
