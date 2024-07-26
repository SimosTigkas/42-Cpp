/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:59:17 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/26 17:42:15 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): AAnimal()
{
    this->type = "Cat";
    std::cout << "Cat Default Constructor has been called.\n" << std::endl;
    this->brain = new Brain();
    if (!this->brain)
    {
        std::cout << "Cat's brain could not be allocated" << std::endl;
        exit(EXIT_FAILURE);
    }
}

Cat::~Cat(void)
{
    std::cout << "\nCat has been destroyed." << std::endl;
}

Cat::Cat(const Cat &a_copy): AAnimal(a_copy)
{
    *this = a_copy;
    std::cout << "Cat Copy Constructor has been called." << std::endl;
}

Cat &Cat::operator=(const Cat &og)
{
    std::cout << "Cat assignment operator has been called." << std::endl;
    if (this != &og)
    {
        this->type = og.type;
        this->brain = new Brain();
        if (!this->brain)
        {
            std::cout << "Cat's brain could not be allocated" << std::endl;
            exit(EXIT_FAILURE);
        }
        return (*this);
    }
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << this->type << " says ~> Moewww moewww!!" << std::endl;
}

void Cat::getIdeas(void) const
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

void Cat::setIdea(int i, std::string idea)
{
    this->brain->setIdea(i, idea);
}