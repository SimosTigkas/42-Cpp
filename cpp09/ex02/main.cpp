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

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Try this: ./PmergeMe nbr1 nbr2 nbr3..." << std::endl;
        return (1);
    }
    try
    {
        PmergeMe setOfNums(av + 1);
        std::cout << "Before: ";
        setOfNums.printVector();
        //sorting the vector and the deque
        std::cout << "After: ";
        setOfNums.printVector();
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << std::endl; 
	    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}