/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:48:20 by stigkas           #+#    #+#             */
/*   Updated: 2025/01/21 14:48:20 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
   // std::cout << "PmergeMe Default Constructor has been called" << std::endl;
}

PmergeMe::PmergeMe(char **input)
{
    //something
}

PmergeMe::PmergeMe(const PmergeMe &a_copy)
{
    // std::cout << "PmergeMe Copy Constructor has been called" <<std::endl;
    *this = a_copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &og)
{
    // std::cout << "PmergeMe assignment operator has been called." << std::endl;
    if (this != &og)
    {
        myVector = og.myVector;
        myDeque = og.myDeque;
    }
    return *this;
}

PmergeMe::~PmergeMe(void)
{
    // std::cout << "PmergeMe Destructor has been called" << std::endl;
}

void PmergeMe::sortVector(void)
{
    //tomorrow
}

void PmergeMe::printVector(void)
{
    //tomorrow
}

void PmergeMe::sortDeque(void)
{
    //tomorrow
}
