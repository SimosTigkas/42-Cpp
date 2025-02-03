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

long jacobsthal_num(long n)
{
    long jNmro = pow(2, n + 1) + pow(-1, n)/3;
    return (round((jNmro)));
}

std::vector<std::vector<int>::iterator>::iterator PmergeMe::BinarySearchV(
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

void PmergeMe::sortVector(int numsPerPair)
{
    int isOddElement = 0;
    size_t j = 4;
    size_t pairsCounter = myVector.size() / numsPerPair;

    if (pairsCounter < 2)
        return;
    if (pairsCounter % 2)
        isOddElement = 1;
    std::vector<int>::iterator first = myVector.begin();
    std::vector<int>::iterator last = myVector.begin() + numsPerPair * pairsCounter;
    std::vector<int>::iterator end = last - isOddElement * numsPerPair;
    size_t step = numsPerPair * 2;
    std::vector<int>::iterator i = first;
    while (i != end)
    {
        std::vector<int>::iterator curr = i + numsPerPair - 1;
        std::vector<int>::iterator nextOne = i + numsPerPair * 2 - 1;
        if (nextOne >= myVector.end())
            break;
        if (*curr > *nextOne)
        {
            std::vector<int>::iterator newFirst = i - numsPerPair + 1;
            std::vector<int>::iterator newEnd = newFirst + numsPerPair;
            if (newFirst < myVector.begin() || newEnd > myVector.end())
                return;
            while (newFirst != newEnd)
            {
                if (newFirst + numsPerPair >= myVector.end())
                    break;
                std::iter_swap(newFirst, newFirst + numsPerPair);
                newFirst++;
            }

        }
        i += step;
    }
    if (static_cast<size_t>(numsPerPair * 2) > myVector.size())
        return;
    sortVector(numsPerPair * 2);
    std::vector<std::vector<int>::iterator> main;
    std::vector<std::vector<int>::iterator> pend;
    main.push_back(myVector.begin() + numsPerPair - 1);
    main.push_back(myVector.begin() + numsPerPair * 2 - 1);
    while (j <= pairsCounter)
    {
        if (numsPerPair * (j - 1) - 1 >= myVector.size())
            break;
        pend.push_back(myVector.begin() + numsPerPair * (j - 1) - 1);
        main.push_back(myVector.begin() + numsPerPair * j - 1);
        j += 2;
    }
    int prevJ = jacobsthal_num(1);
    int numsInserted = 0;
    int n = 2;
    while (true)
    {
        int currJ = jacobsthal_num(n);
        size_t jacobsthalDiff = currJ - prevJ;
        int bound_adjustment = 0;
        if (jacobsthalDiff > pend.size())
            break;
        int remaining_insertions = static_cast<int>(jacobsthalDiff);
        std::vector<std::vector<int>::iterator>::iterator pend_iterator = pend.begin() + jacobsthalDiff - 1;
        std::vector<std::vector<int>::iterator>::iterator bound_iterator = main.begin() + currJ + numsInserted;
        while (remaining_insertions)
        {
            std::vector<std::vector<int>::iterator>::iterator index = BinarySearchV(main.begin(), bound_iterator, *pend_iterator);
            if (index >= main.end())
                index = main.end();
            std::vector<std::vector<int>::iterator>::iterator insertionPosition = main.insert(index, *pend_iterator);
            remaining_insertions--;
            pend_iterator = pend.erase(pend_iterator);
            pend_iterator--;
            if (insertionPosition - main.begin() == currJ + numsInserted)
                bound_adjustment++;
            bound_iterator = main.begin() + currJ + numsInserted - bound_adjustment;
        }
        prevJ = currJ;
        numsInserted += jacobsthalDiff;
        if (bound_adjustment != 0)
            bound_adjustment = 0;
        n++;
    }
    for (size_t k = 0; k < pend.size(); k++)
    {
        std::vector<std::vector<int>::iterator>::iterator pend_element = pend.begin() + k;
        std::vector<std::vector<int>::iterator>::iterator main_bound = main.begin() + main.size() - pend.size() + k;
        std::vector<std::vector<int>::iterator>::iterator index = BinarySearchV(main.begin(), main_bound, *pend_element);
        if (index >= main.end())
            index = main.end();
        main.insert(index, *pend_element);
    }
    std::vector<int> temp;
    temp.reserve(myVector.size());
    std::vector<std::vector<int>::iterator>::iterator iter = main.begin();
    while (iter != main.end())
    {
        std::vector<int>::iterator group_start = *iter - (numsPerPair - 1);
        for (int k = 0; k < numsPerPair; k++)
        {
            temp.push_back(*(group_start + k));
        }
        iter++;
    }
    std::copy(temp.begin(), temp.end(), myVector.begin());
}

// void PmergeMe::sortDeque(int numsPerPair)
// {
//     int isOddElement = 0;
//     int j = 4;
//     int pairsCounter = myDeque.size() / numsPerPair;
//     if (pairsCounter < 2)
//         return;
//     if (pairsCounter % 2)
//         isOddElement = 1;
//     std::deque<int>::iterator first = myDeque.begin();
//     std::deque<int>::iterator last = myDeque.begin();
//     std::advance(last, numsPerPair * pairsCounter);
//     std::deque<int>::iterator end = last;
//     if (isOddElement)
//         std::advance(end, -numsPerPair);
//     int step = numsPerPair * 2;
//     std::deque<int>::iterator i = first;
//     while (i != end)
//     {
//         std::deque<int>::iterator curr = i;
//         std::advance(curr, numsPerPair - 1);
//         std::deque<int>::iterator nextOne = i;
//         std::advance(nextOne, numsPerPair * 2 - 1);
//         if (*curr > *nextOne)
//         {
//             std::deque<int>::iterator newFirst = i;
//             std::advance(newFirst, -numsPerPair + 1);
//             std::deque<int>::iterator newEnd = newFirst;
//             std::advance(newEnd, numsPerPair);
//             while (newFirst != newEnd)
//             {
//                 std::iter_swap(newFirst, newFirst + numsPerPair);
//                 std::advance(newFirst, 1);
//             }
//         }
//         std::advance(i, step);
//     }
//     sortDeque(numsPerPair * 2);
//     std::deque<std::deque<int>::iterator> main;
//     std::deque<std::deque<int>::iterator> pend;
//     main.push_back(myDeque.begin() + numsPerPair - 1);
//     main.push_back(myDeque.begin() + numsPerPair * 2 - 1);
//     while (j <= pairsCounter)
//     {
//         std::deque<int>::iterator pendElement = myDeque.begin() + numsPerPair * (j - 1) - 1;
//         pend.push_back(pendElement);
//         main.push_back(myDeque.begin() + numsPerPair * j - 1);
//         j += 2;
//     }
//     int prevJ = jacobsthal_num(1);
//     int numsInserted = 0;
//     int n = 2;
//     while (true)
//     {
//         int currJ = jacobsthal_num(n);
//         size_t jacobsthalDiff = currJ - prevJ;
//         int bound_adjustment = 0;
//         if (jacobsthalDiff > pend.size())
//             break;
//         int remaining_insertions = static_cast<int>(jacobsthalDiff);
//         std::deque<std::deque<int>::iterator>::iterator pendIterator = pend.begin() + jacobsthalDiff - 1;
//         std::deque<std::deque<int>::iterator>::iterator boundIterator = main.begin() + currJ + numsInserted;
//         while (remaining_insertions)
//         {
//             std::deque<std::deque<int>::iterator>::iterator index = BinarySearchD(main.begin(), boundIterator, *pendIterator);
//             std::deque<std::deque<int>::iterator>::iterator insertionPosition = main.insert(index, *pendIterator);
//             remaining_insertions--;
//             pendIterator = pend.erase(pendIterator);
//             std::advance(pendIterator, -1);
//             if (insertionPosition - main.begin() == currJ + numsInserted)
//                 bound_adjustment++;

//             boundIterator = main.begin() + currJ + numsInserted - bound_adjustment;
//         }
//         prevJ = currJ;
//         numsInserted += jacobsthalDiff;
//         if (bound_adjustment != 0)
//             bound_adjustment = 0;
//         n++;
//     }
//     size_t k = 0;
//     while (k < pend.size())
//     {
//         std::deque<std::deque<int>::iterator>::iterator pendElement = pend.begin() + k;
//         std::deque<std::deque<int>::iterator>::iterator mainBound = main.begin() + main.size() - pend.size() + k;
//         std::deque<std::deque<int>::iterator>::iterator index = BinarySearchD(main.begin(), mainBound, *pendElement);
//         main.insert(index, *pendElement);
//         k++;
//     }
//     if (isOddElement == 1)
//     {
//         std::deque<int>::iterator oddPair = end;
//         std::advance(oddPair, numsPerPair - 1);
//         std::deque<std::deque<int>::iterator>::iterator index = BinarySearchD(main.begin(), main.end(), oddPair);
//         main.insert(index, oddPair);
//     }
//     std::deque<int> temp;
//     std::deque<std::deque<int>::iterator>::iterator mainIter = main.begin();
//     while (mainIter != main.end())
//     {
//         std::deque<int>::iterator groupStart = *mainIter;
//         for (int k = 0; k < numsPerPair; k++)
//         {
//             temp.push_back(*(groupStart + k));
//         }
//         std::advance(mainIter, 1);
//     }
//     std::copy(temp.begin(), temp.end(), myDeque.begin());
// }

bool PmergeMe::vectorIsSorted(void) const
{
    return std::adjacent_find(myVector.begin(), myVector.end(), std::greater<int>()) == myVector.end();
}

bool PmergeMe::dequeIsSorted(void) const
{
    return std::adjacent_find(myDeque.begin(), myDeque.end(), std::greater<int>()) == myDeque.end();
}
