/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:59:17 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/23 12:54:32 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal()
{
    this->type = "Cat";
    std::cout << "Cat Default Constructor has been called.\n" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "\nCat has been destroyed." << std::endl;
}

Cat::Cat(const Cat &a_copy): Animal(a_copy)
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
        return (*this);
    }
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << this->type << " says ~> Moewww moewww!!" << std::endl;
}