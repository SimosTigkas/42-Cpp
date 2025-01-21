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

class PmergeMe
{
    private:

    public:
        PmergeMe(void);
        PmergeMe(const std::string& input);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe &a_copy);
        PmergeMe &operator=(const PmergeMe &og);
};





#endif