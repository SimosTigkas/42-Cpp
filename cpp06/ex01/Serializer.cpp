/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:13:13 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/05 12:13:13 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
    // std::cout << "Serializer Default Constructor has been called." << std::endl;
}

Serializer::~Serializer(void)
{
    // std::cout << "Serialzer Default Destructor has been called." << std::endl;
}

Serializer& Serializer::operator=(const Serializer &og)
{
    // std::cout << "Serializer assignment operator has been called." << std::endl;
    if (this != &og)
    {
        *this = og;
        return (*this);
    }
    return (*this);
}

Serializer::Serializer(const Serializer &a_copy)
{
    // std::cout << "Seriliazer Copy Constructor has been called." << std::endl;
    *this = a_copy;
}


