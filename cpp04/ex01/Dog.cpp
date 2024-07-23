/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:00:42 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/23 12:54:32 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal()
{
    this->type = "Dog";
    std::cout << this->type << " Default Constructor has been called." << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "\nDog has been destroyed." << std::endl;
}

Dog::Dog(const Dog &a_copy): Animal(a_copy)
{
    *this = a_copy;
    std::cout << "Dog Copy Constructor has been called." << std::endl;
}

Dog &Dog::operator=(const Dog &og)
{
    std::cout << "Dog assignment operator has been called." << std::endl;
    if (this != &og)
    {
        this->type = og.type;
        return (*this);
    }
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << this->type << " says ~> Woof wof!!" << std::endl;
}