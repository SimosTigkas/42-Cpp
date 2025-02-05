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
    std::deque<int>::const_iterator it = myDeque.begin();
    while (it != myDeque.end())
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

// std::vector<int>::iterator PmergeMe::BinarySearchV(
//     std::vector<int>::iterator begin,
//     std::vector<int>::iterator end,
//     int target)
// {
//     while (begin < end)
//     {
//         std::vector<int>::iterator mid = begin + (end - begin) / 2;
//         if (target <= *mid)
//             end = mid;
//         else
//             begin = mid + 1;
//     }
//     return begin;
// }

// void PmergeMe::sortVector(size_t numsPerPair)
// {
//     if (myVector.size() < 2)
//         return;
//     size_t pairsCounter = myVector.size() / numsPerPair;
//     if (pairsCounter < 2)
//         return;
//     std::vector<int>::iterator first = myVector.begin();
//     std::vector<int>::iterator last = myVector.begin() + numsPerPair * pairsCounter;
//     size_t step = numsPerPair * 2;
//     std::vector<int>::iterator i = first;
//     // **Step 1: Properly Swap Pairs**
//     while (i + numsPerPair < last)  // Ensure no out-of-bounds access
//     {
//         std::vector<int>::iterator curr = i;
//         std::vector<int>::iterator nextOne = i + numsPerPair;

//         if (*curr > *nextOne)
//             std::swap_ranges(curr, curr + numsPerPair, nextOne);  // Swap entire pair

//         i += step;
//     }
//     // **Step 2: Recursively Sort Larger Groups**
//     if (numsPerPair * 2 <= myVector.size())
//         sortVector(numsPerPair * 2);
//     std::vector<int> main;
//     std::vector<int> pend;
//     // **Step 3: Partition Elements into Main and Pending**
//     size_t j = 2;
//     while (j <= pairsCounter)
//     {
//         pend.push_back(myVector[numsPerPair * (j - 1) - 1]);
//         main.push_back(myVector[numsPerPair * j - 1]);
//         j += 2;
//     }
//     // **Step 4: Jacobsthal Sequence Insertion**
//     int prevJ = jacobsthal_num(1);
//     int numsInserted = 0;
//     int n = 2;
//     while (true)
//     {
//         int currJ = jacobsthal_num(n);
//         size_t jacobsthalDiff = currJ - prevJ;
//         if (jacobsthalDiff > pend.size())
//             break;
//         std::vector<int> elementsToInsert;
//         for (size_t k = 0; k < jacobsthalDiff; k++)
//             elementsToInsert.push_back(pend[k]);
//         pend.erase(pend.begin(), pend.begin() + jacobsthalDiff);
//         for (size_t k = 0; k < elementsToInsert.size(); k++)
//         {
//             // Directly use BinarySearchV without finding the target
//             std::vector<int>::iterator index = BinarySearchV(main.begin(), main.end(), elementsToInsert[k]);
//             main.insert(index, elementsToInsert[k]);
//         }
//         prevJ = currJ;
//         numsInserted += jacobsthalDiff;
//         n++;
//     }
//     // **Step 5: Insert Remaining Pending Elements**
//     for (size_t k = 0; k < pend.size(); k++)
//     {
//         // Directly use BinarySearchV without finding the target
//         std::vector<int>::iterator index = BinarySearchV(main.begin(), main.end(), pend[k]);
//         main.insert(index, pend[k]);
//     }
//     // **Step 6: Copy Sorted Elements Back to myVector**
//     myVector = main;
// }

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

