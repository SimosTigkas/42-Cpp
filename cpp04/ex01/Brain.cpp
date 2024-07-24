/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:05:15 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/24 13:36:47 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor has been called." << std::endl;
}

Brain::Brain(const Brain &a_copy)
{
    std::cout << "Brain Copy constructor has been called." << std::endl;
    *this = a_copy;
}

Brain &Brain::operator=(const Brain &og)
{
    int i=0;
    if (this != &og)
    {
        while (i < 100)
        {
            this->ideas[i] = og.ideas[i];
            i++;
        }
        return (*this);
    }
    return (*this);
}

Brain::~Brain(void)
{
    std::cout << "Brain has been destroyed.." << std::endl;
}