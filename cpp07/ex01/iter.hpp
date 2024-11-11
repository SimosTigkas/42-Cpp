/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:15:11 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/07 14:15:11 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <iomanip>

template <typename T>
void ft_print(T sth)
{
    if constexpr (std::is_floating_point<T>::value)
        std::cout << std::fixed << std::setprecision(1) << sth << std::endl;
    else
        std::cout << sth << std::endl;
}

template <typename T>
void iter(T *arr, size_t len, void (*f)(T))
{
    size_t i = 0;
    if (len > sizeof(arr) || len < 1)
        return ;
    while (i < len)
    {
        f(arr[i]);
        i++;
    }
}

#endif