/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:38:00 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/31 11:38:00 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// ScalarConverter::ScalarConverter(void)
// {
//     std::cout << "ScalarConverter Default constructor has been called." << std::endl;
// }

// ScalarConverter::~ScalarConverter(void)
// {
//     std::cout << "ScalarConvertor Destructor has been called." << std::endl;
// }

// ScalarConverter::ScalarConverter(const ScalarConverter &a_copy)
// {
//     std::cout << "ScalarConvertor Copy Constructor has been called." << std::endl;
// }

// ScalarConverter &ScalarConverter::operator=(const ScalarConverter& og)
// {
//     std::cout << "ScalarConvertor assignment operator has been called." << std::endl;
// }

static void charConv(std::string type)
{
    //tomorrow
}

static void intConv(std::string type)
{
    //tomorrow
}

static void floatConv(std::string type)
{
    //tomorrow
}

static void doubleConv(std::string type)
{
    //tomorrow
}

static int getType(std::string unknown)
{
    if (unknown.length() == 1 && !std::isdigit(unknown[0]))
        return 0;
    /*
        if: for INT
    */
    if (unknown == "-inff" || unknown == "inf")
        return 2;
    if (unknown == "-inf" || unknown == "inf" || unknown == "nan")
        return 3;
}

static void errorHandler(std::string differentType)
{
    std::cout << "This " << differentType << " type conversion is impossible to happen. Please try again with char/int/float/double." << std::endl;
}
void ScalarConverter::convert(std::string type)
{
    void (*differentTypes[5])(std::string) = {&charConv, &intConv, &floatConv, &doubleConv, &errorHandler};
    differentTypes[getType(type)](type);
}