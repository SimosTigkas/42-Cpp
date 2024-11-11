/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:12:28 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/07 14:12:28 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <climits>
#include <iostream>

template <typename T>
class Array
{
    private:
        T *arr;
        unsigned int ssize;
   public:
        Array(void);
        Array(unsigned int n);
        ~Array(void);
        Array(Array const &a_copy);
        Array           &operator=(Array const &og);
        T               &operator[](unsigned int i) const;
        unsigned int    size() const;
        class AccessFailed : public std::exception {
            public:
                const char *what(void) const throw();
        };
};

#endif