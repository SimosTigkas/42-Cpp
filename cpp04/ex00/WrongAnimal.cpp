/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:06:25 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/23 13:20:53 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    this->type = "Random_WrongAnimal";
    std::cout << "\nWrongAnimal " << this->type << " Default Constructor has been called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string name): type(name)
{   
    this->type = "Random_Wronganimal";
    std::cout << "WrongAnimal " << this->type << " has been created!!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a_copy)
{
    this->type = a_copy.type;
    std::cout << "WrongAnimal " << this->type << "Copy Constructor has been called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &og)
{
    std::cout << "WrongAnimal assignment operator has been called." << std::endl;
    if (this != &og)
    {
        this->type = og.type;
        return (*this);
    }
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal " << this->type << " has been destroyed." << std::endl;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "\nThis WrongAnimal does not know which sound to make...\n" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}