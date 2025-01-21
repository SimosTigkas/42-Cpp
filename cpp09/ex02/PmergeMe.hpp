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
# include <iostream>
# include <iomanip>
# include <ctime>

class PmergeMe
{
    private:
        std::vector<int> myVector;
        std::deque<int> myDeque;
    public:
        PmergeMe(void);
        PmergeMe(char **input);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe &a_copy);
        PmergeMe &operator=(const PmergeMe &og);

        void sortVector(void);
        void printVector(void);
        void sortDeque(void);
};





#endif