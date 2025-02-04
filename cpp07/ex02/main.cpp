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

int main(void)
{
    Array<int> ints(5);
    ints[0] = 1;
    ints[1] = 2;
    ints[2] = 3;
    ints[3] = 4;
    ints[4] = 5;
    std::cout << "ints[0]= " << ints[0] << std::endl;
    std::cout << "ints[1]= " << ints[1] << std::endl;
    std::cout << "ints[2]= " << ints[2] << std::endl;
    std::cout << "ints[3]= " << ints[3] << std::endl;
    std::cout << "ints[4]= " << ints[4] << std::endl;
    try{
        ints[24] = 25;
    }
    catch (std::exception &e) {
        std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;    
    }
    try{
        ints[2] = 23;
        std::cout << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;    
    }
    try {
        std::cout << "ints[0]= " << ints[0] << std::endl;
        std::cout << "ints[1]= " << ints[1] << std::endl;
        std::cout << "ints[2]= " << ints[2] << std::endl;
        std::cout << "ints[3]= " << ints[3] << std::endl;
        std::cout << "ints[4]= " << ints[4] << std::endl;
        std::cout << "The size of ints() is: " << ints.size() <<std::endl;

        Array<int> a(5);
        a[0] = 1;
        a[1] = 2;
        a[2] = 3;
        a[3] = 4;
        a[4] = 5;

        Array<int> b(3);
        b[0] = 5;
        b[1] = 6;
        b[2] = 7;
        b[0] = a[4];
        std::cout << "b[0]: " << b[3] <<std::endl;
    }
    catch(std::exception &e) {
        std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
    }
}