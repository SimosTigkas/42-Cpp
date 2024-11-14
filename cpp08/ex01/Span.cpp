/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:54:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/14 12:31:24 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
    this->size = 0;
    this->vec = {};    
}

Span::Span(unsigned int nmro) {
    this->size = nmro;
}

Span::~Span(void) {};

Span::Span(const Span &a_copy)
{
    this->size = a_copy.size;
    this->vec = a_copy.vec;
}

Span &Span::operator=(const Span &og)
{
    if (this != &og)
    {
        this->size = og.size;
        this->vec = og.vec;
        return (*this);
    }
    return (*this);
}

void Span::addNumber(int nmro)
{
    if (this->size == vec.size())
        throw VecIsFullException();
    else
        vec.push_back(nmro);
}

int Span::shortestSpan(void) const
{
    if (vec.size() < 2)
        throw VecIsTooSmallException();
    std::vector<int>::const_iterator i;
    std::vector<int>::const_iterator j;
    int temp = 0;
    int dist = std::abs(*vec.begin() - *(vec.end() + 1));
    i = vec.begin();
    while (i < vec.end())
    {
        j = i + 1;
        while (j < vec.end())
        {
            temp = std::abs(*j - *i);
            if (temp < dist)
                dist = temp;
            j++;
        }
        i++;
    }
    return (dist);
}

void Span::printSpan(void)
{
    std::vector<int>::const_iterator i;
    i = vec.begin();
    while (i < vec.end())
    {
        std::cout << *i <<std::endl;
        i++;
    }
}

int Span::longestSpan(void) const
{
    if (vec.size() < 2)
        throw VecIsTooSmallException();
    int max_element = *vec.begin();
    int min_element = *vec.begin();
    std::vector<int>::const_iterator i;
    i = vec.begin();
    while (i < vec.end())
    {
        if (*i < min_element)
            min_element = *i;
        if (*i > max_element)
            max_element = *i;
        i++;
    }
    return (max_element - min_element);
}