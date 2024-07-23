/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:34:40 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/23 09:32:13 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal Default Constructor has been called." << std::endl;
}

Animal::Animal(std::string name): type(name)
{
    std::cout << "Animal " << this->type << " has been created!!" << std::endl;
}

Animal::Animal(const Animal &a_copy)
{
    this->type = a_copy.type;
    std::cout << "Animal Copy Constructor has been called." << std::endl;

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

void Animal::makeSound(void)
{
    std::cout << "Not any sound available yet.." << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}