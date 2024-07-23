/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:34:40 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/23 12:56:10 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    this->type = "Random_animal";
    std::cout << "\nAnimal " << this->type << " Default Constructor has been called." << std::endl;
}

Animal::Animal(std::string name): type(name)
{   
    this->type = "Random_animal";
    std::cout << "Animal " << this->type << " has been created!!" << std::endl;
}

Animal::Animal(const Animal &a_copy)
{
    this->type = a_copy.type;
    std::cout << "Animal " << this->type << "Copy Constructor has been called." << std::endl;
}

Animal &Animal::operator=(const Animal &og)
{
    std::cout << "Animal assignment operator has been called." << std::endl;
    if (this != &og)
    {
        this->type = og.type;
        return (*this);
    }
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "Animal " << this->type << " has been destroyed." << std::endl;
}

void Animal::makeSound(void) const
{
    std::cout << "This animal does not know which sound to make...\n" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}