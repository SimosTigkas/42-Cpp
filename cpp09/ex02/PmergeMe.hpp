/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:48:53 by stigkas           #+#    #+#             */
/*   Updated: 2025/01/21 14:48:53 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <iomanip>
# include <ctime>
# include <climits>
# include <cstdlib>
# include <cctype>
# include <cmath>
# include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> myVector;
        std::deque<int> myDeque;
    public:
        PmergeMe(void);
        PmergeMe(int ac, char **input);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe &a_copy);
        PmergeMe &operator=(const PmergeMe &og);

        void sortVector(void);
        void printVector(void);
        std::vector<std::vector<int>::iterator>::iterator BinarySearchIteratorsV(std::vector<std::vector<int>::iterator>::iterator begin, std::vector<std::vector<int>::iterator>::iterator end, std::vector<int>::iterator target);
        std::vector<int>::iterator BinarySearchV(std::vector<int>::iterator begin, std::vector<int>::iterator end, int target);
        void sortDeque(void);
        std::deque<std::deque<int>::iterator>::iterator BinarySearchD(std::deque<std::deque<int>::iterator>::iterator begin, std::deque<std::deque<int>::iterator>::iterator end, std::deque<int>::iterator target);
        bool vectorIsSorted(void) const;
        bool dequeIsSorted(void) const;
};

bool parseInput(int ac, char **av);
long jacobsthal_num(long n);
bool compareIterators(std::deque<int>::iterator a, std::deque<int>::iterator b);
bool compareIters(std::vector<int>::iterator a, std::vector<int>::iterator b);

#endif