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

PmergeMe::PmergeMe(int size, char **input)
{
    myVector.reserve(size - 1);
    input++;
    while (*input)
    {
        myVector.push_back(atoi(*input));
        input++;
    }
    input -= (size - 1);
    int i = 0;
    while (i < size - 1)
    {
        myDeque.push_back(atoi(input[i]));
        i++;
    }
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

void PmergeMe::printVector(void)
{
    std::vector<int>::const_iterator it = myVector.begin();
    while (it != myVector.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}


std::deque<std::deque<int>::iterator>::iterator PmergeMe::BinarySearchD(
    std::deque<std::deque<int>::iterator>::iterator begin,
    std::deque<std::deque<int>::iterator>::iterator end,
    std::deque<int>::iterator target)
{
    while (begin < end)
    {
        std::deque<std::deque<int>::iterator>::iterator mid = begin + (end - begin) / 2;
        if (*target < **mid) 
            end = mid;
        else
            begin = mid + 1;
    }
    return begin;
}

long jacobsthal_num(long n)
{
    return ((1 << (n + 1)) + ((n % 2 == 0) ? 1 : -1)) / 3;
}

bool compareIters(std::vector<int>::iterator a, std::vector<int>::iterator b)
{
    return *a < *b;
}


std::vector<std::vector<int>::iterator>::iterator PmergeMe::BinarySearchIteratorsV(
    std::vector<std::vector<int>::iterator>::iterator begin,
    std::vector<std::vector<int>::iterator>::iterator end,
    std::vector<int>::iterator target)
{
    while (begin < end)
    {
        std::vector<std::vector<int>::iterator>::iterator mid = begin + (end - begin) / 2;
        if (*target < **mid)
            end = mid;
        else
            begin = mid + 1;
    }
    return begin;
}

std::vector<int>::iterator PmergeMe::BinarySearchV(
    std::vector<int>::iterator begin,
    std::vector<int>::iterator end,
    int target)
{
    while (begin < end)
    {
        std::vector<int>::iterator mid = begin + (end - begin) / 2;
        if (target <= *mid)
            end = mid;
        else
            begin = mid + 1;
    }
    return begin;
}

void PmergeMe::sortVector(void)
{
    if (myVector.size() < 2)
        return;

    std::vector<int> main;
    std::vector<int> pend;
    std::vector<std::vector<int>::iterator> mainIterators;
    std::vector<std::vector<int>::iterator> pendIterators;

    for (size_t i = 0; i + 1 < myVector.size(); i += 2)
    {
        if (myVector[i] > myVector[i + 1])
            std::swap(myVector[i], myVector[i + 1]);
    }

    for (size_t i = 1; i < myVector.size(); i += 2)
    {
        main.push_back(myVector[i]);
        mainIterators.push_back(myVector.begin() + i);
    }
    for (size_t i = 0; i < myVector.size(); i += 2)
    {
        pend.push_back(myVector[i]);
        pendIterators.push_back(myVector.begin() + i);
    }

    std::sort(main.begin(), main.end());
    std::sort(mainIterators.begin(), mainIterators.end(), compareIters);

    std::vector<int> insertionOrder;
    size_t jacobIndex = 1;
    while (jacobsthal_num(jacobIndex) - 1 < static_cast<long>(pend.size()))
    {
        insertionOrder.push_back(jacobsthal_num(jacobIndex) - 1);
        jacobIndex++;
    }

    for (size_t j = 0; j < insertionOrder.size(); j++)
    {
        size_t i = insertionOrder[j];
        if (i < pendIterators.size())
        {
            std::vector<int>::iterator pos = BinarySearchV(main.begin(), main.end(), *pendIterators[i]);
            main.insert(pos, *pendIterators[i]);
            std::vector<std::vector<int>::iterator>::iterator iterPos = BinarySearchIteratorsV(
                mainIterators.begin(), mainIterators.end(), pendIterators[i]);
            mainIterators.insert(iterPos, pendIterators[i]);
        }
    }

    for (size_t i = 0; i < pendIterators.size(); i++)
    {
        bool alreadyInserted = false;
        for (size_t j = 0; j < insertionOrder.size(); j++)
        {
            if (insertionOrder[j] == static_cast<int>(i))
            {
                alreadyInserted = true;
                break;
            }
        }
        if (!alreadyInserted)
        {
            std::vector<int>::iterator pos = BinarySearchV(main.begin(), main.end(), *pendIterators[i]);
            main.insert(pos, *pendIterators[i]);
            std::vector<std::vector<int>::iterator>::iterator iterPos = BinarySearchIteratorsV(
                mainIterators.begin(), mainIterators.end(), pendIterators[i]);
            mainIterators.insert(iterPos, pendIterators[i]);
        }
    }
    myVector.assign(main.begin(), main.end());
}

bool compareIterators(std::deque<int>::iterator a, std::deque<int>::iterator b)
{
    return *a < *b;
}

void PmergeMe::sortDeque(void)
{
    if (myDeque.size() < 2)
        return;
    std::deque<int> main;
    std::deque<int> pend;
    std::deque<std::deque<int>::iterator> mainIterators;
    std::deque<std::deque<int>::iterator> pendIterators;

    for (size_t i = 0; i + 1 < myDeque.size(); i += 2)
    {
        if (myDeque[i] > myDeque[i + 1])
            std::swap(myDeque[i], myDeque[i + 1]);
    }

    for (size_t i = 1; i < myDeque.size(); i += 2)
    {
        main.push_back(myDeque[i]);
        mainIterators.push_back(myDeque.begin() + i);
    }
    for (size_t i = 0; i < myDeque.size(); i += 2)
    {
        pend.push_back(myDeque[i]);
        pendIterators.push_back(myDeque.begin() + i);
    }

    std::sort(main.begin(), main.end());
    std::sort(mainIterators.begin(), mainIterators.end(), compareIterators);

    std::deque<int> insertionOrder;
    size_t jacobIndex = 1;
    while (jacobsthal_num(jacobIndex) - 1 < static_cast<long>(pend.size()))
    {
        insertionOrder.push_back(jacobsthal_num(jacobIndex) - 1);
        jacobIndex++;
    }

    for (size_t j = 0; j < insertionOrder.size(); j++)
    {
        size_t i = insertionOrder[j];
        if (i < pendIterators.size())
        {
            std::deque<std::deque<int>::iterator>::iterator pos = BinarySearchD(mainIterators.begin(), mainIterators.end(), pendIterators[i]);
            mainIterators.insert(pos, pendIterators[i]);
        }
    }

    for (size_t i = 0; i < pendIterators.size(); i++)
    {
        bool alreadyInserted = false;
        for (size_t j = 0; j < insertionOrder.size(); j++)
        {
            if (insertionOrder[j] == static_cast<int>(i))
            {
                alreadyInserted = true;
                break;
            }
        }
        if (!alreadyInserted)
        {
            std::deque<std::deque<int>::iterator>::iterator pos = BinarySearchD(mainIterators.begin(), mainIterators.end(), pendIterators[i]);
            mainIterators.insert(pos, pendIterators[i]);
        }
    }
    std::deque<int> sortedDeque;
    for (size_t i = 0; i < mainIterators.size(); i++)
    {
        sortedDeque.push_back(*mainIterators[i]);
    }
    myDeque.assign(sortedDeque.begin(), sortedDeque.end());
}




bool PmergeMe::vectorIsSorted(void) const
{
    return std::adjacent_find(myVector.begin(), myVector.end(), std::greater<int>()) == myVector.end();
}

bool PmergeMe::dequeIsSorted(void) const
{
    for (size_t i = 1; i < myDeque.size(); ++i)
    {
        if (myDeque[i - 1] > myDeque[i])
            return false;
    }
    return true;
}

