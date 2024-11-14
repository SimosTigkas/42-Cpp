/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:36:56 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/14 13:47:39 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <algorithm>
# include <iterator>
# include <list>

template <typename T>
class MutantStack: public std::stack<T>
{
    private:
    public:
        MutantStack(void);
        ~MutantStack(void);
        MutantStack(const MutantStack &a_copy);
        MutantStack &operator=(const MutantStack &og);
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator citerator;
        iterator begin()
        {
            return (std::stack<T>::c.begin());
        }
        iterator end()
        {
            return (std::stack<T>::c.end());
        }
        citerator begin() const
        {
            return (std::stack<T>::c.begin());
        }
        citerator end() const
        {
            return (std::stack<T>::c.end());
        }
};

#endif