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
        Array(void){
            this->arr = nullptr;
            this->ssize = 0;
        }
        Array(unsigned int n){
            arr = new T[n]();
            ssize = n;
        }
        ~Array(void){
            delete[] arr;
        }
        Array(Array const &a_copy){
            unsigned int i=0;
            ssize = a_copy.ssize;
            arr = new T[ssize];
            while (i < ssize)
            {
                arr[i] = a_copy.arr[i];
                i++;
            }
        }
        Array   &operator=(Array const &og)
        {
            if (this != &og)
            {
                delete [] arr;
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
        T   &operator[](unsigned int i) const {
            if (i >= ssize || i > INT_MAX)
                throw AccessFailed();
            return *(arr + i);
        }
        unsigned int    size() const {  return ssize; }
        class AccessFailed : public std::exception {
            public:
                const char *what(void) const throw() {
                    const char *error = "You cannot access this array at this index.";
                    return error;
                }
        };
};

#endif