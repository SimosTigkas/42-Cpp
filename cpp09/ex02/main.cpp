/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:39:06 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/18 17:39:06 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool parseInput(int ac, char **av)
{
    int i = 1;
    while (i < ac)
    {
        std::string arg = av[i];
        size_t j = 0;
        if (arg[j] == '+')
            j++;
        else if (arg[j] == '-')
            return (false);
        while (j < arg.length() && std::isdigit(arg[j]))
            j++;
        if (j != arg.length())
            return (false);
        long nmro = std::strtol(arg.c_str(), nullptr, 10);
        if (nmro > INT_MAX || nmro < INT_MIN)
            return (false);
        i++;
    }
    return true;
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Try this: ./PmergeMe nbr1 nbr2 nbr3..." << std::endl;
        return (1);
    }
    if (!parseInput(ac, av))
    {
        std::cout << "The input is invalid" <<std::endl;
        return (2);
    }
    try
    {
        PmergeMe setOfNums(ac, av);
        std::cout << "Before: ";
        setOfNums.printVector();
        clock_t beginningV = clock();
        setOfNums.sortVector(1);
        clock_t endV = clock();
        // clock_t beginningD = clock();
        // std::cout << "before deque sorting" << std::endl;
        // setOfNums.sortDeque(1); //segfaults
        // std::cout << "after deque sorting" << std::endl;
        // clock_t endD = clock();
        if (/*!setOfNums.dequeIsSorted() ||*/ !setOfNums.vectorIsSorted())
            throw std::runtime_error("Sorting did not work");
        std::cout << "After: ";
        setOfNums.printVector();
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << std::fixed << std::setprecision(6) << static_cast<double>(endV - beginningV) / CLOCKS_PER_SEC << " us"<<std::endl; 
	    // std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " <<  std::fixed << std::setprecision(6) << static_cast<double>(endD - beginningD) / CLOCKS_PER_SEC  << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}