/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:00:42 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/26 17:42:01 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): AAnimal()
{
    this->type = "Dog";
    std::cout << this->type << " Default Constructor has been called." << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "\nDog has been destroyed." << std::endl;
}

Dog::Dog(const Dog &a_copy): AAnimal(a_copy)
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

void Dog::getIdeas(void) const
{
    int i = 0;
    while (i < 100)
    {
        std::cout << "Idea number " << i << " is: " 
            << this->brain->getIdea(i) << "with address ->" 
            << this->brain->getIdeaAddress(i) << std::endl;
        i++;
    }    
}

void Dog::setIdea(int i, std::string idea)
{
    this->brain->setIdea(i, idea);
}