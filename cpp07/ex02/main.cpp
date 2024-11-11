/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:12:04 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/07 14:12:04 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
    this->arr = nullptr;
    this->ssize = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    arr = new T[n];
    ssize = n;
}

template <typename T>
Array<T>::~Array(void)
{
    delete[] arr;
}

template <typename T>
Array<T>::Array(Array const &a_copy)
{
    unsigned int i=0;
    ssize = a_copy.ssize;
    arr = new T[ssize];
    while (i < ssize)
    {
        arr[i] = a_copy.arr[i];
        i++;
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &og)
{
    if (this != &og)
    {
        unsigned int i=0;
        ssize = og.ssize;
        arr = new T[ssize];
        while (i < ssize)
        {
            arr[i] = og.arr[i];
            i++;
        }
        return (*this);
    }
    return (*this);
}

template <typename T>
const char *Array<T>::AccessFailed::what() const throw()
{
    const char *error = "You cannot access this array at this index.";
    return error;
}

template <typename T>
T &Array<T>::operator[](const unsigned int i) const
{
    if (i >= ssize || i > INT_MAX)
        throw AccessFailed();
    return *(arr + i);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return ssize;
}

int main(void)
{
    Array<int> ints(5);
    ints[0] = 1;
    ints[1] = 2;
    ints[2] = 3;
    ints[3] = 4;
    ints[4] = 5;
    try{
        ints[24] = 25;
    }
    catch (std::exception &e) {
        std::cerr << "\033[31mIndex is too high. " << e.what() << "\033[0m" << std::endl;    
    }
    try{
        ints[-24] = 23;
    }
    catch (std::exception &e) {
        std::cerr << "\033[31mIndex is too low. " << e.what() << "\033[0m" << std::endl;    
    }
    std::cout << "The size of ints: " << ints.size() << std::endl;
}