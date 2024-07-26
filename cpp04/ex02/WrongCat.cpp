/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:04:07 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/23 13:17:23 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "WrongCat Default Constructor has been called.\n" << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "\nWrongCat has been destroyed." << std::endl;
}

WrongCat::WrongCat(const WrongCat &a_copy): WrongAnimal(a_copy)
{
    *this = a_copy;
    std::cout << "WrongCat Copy Constructor has been called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &og)
{
    std::cout << "WrongCat assignment operator has been called." << std::endl;
    if (this != &og)
    {
        this->type = og.type;
        return (*this);
    }
    return (*this);
}