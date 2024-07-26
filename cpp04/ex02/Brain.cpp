/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:05:15 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/26 17:42:28 by stigkas          ###   ########.fr       */
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
            if (og.ideas[i].length() > 0)
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

const std::string Brain::getIdea(int i) const
{
    if (i < 100)
        return (this->ideas[i]);
    else
    {
        return ("There are only 100 available..");
    }    
}

void Brain::setIdea(int i, std::string idea)
{
    if (i < 100)
        this->ideas[i] = idea;
    else
        std::cout << "There are only 100 available.." << std::endl;
}

const std::string *Brain::getIdeaAddress(int i) const
{
    const std::string &ideaRef = this->ideas[i];
    if (i < 100)
        return (&ideaRef);
    return (nullptr);
}


