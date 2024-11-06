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

ScalarConverter::ScalarConverter(void)
{
    std::cout << "ScalarConverter Default constructor has been called." << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
    std::cout << "ScalarConvertor Destructor has been called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &a_copy)
{
    std::cout << "ScalarConvertor Copy Constructor has been called." << std::endl;
    *this = a_copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& og)
{
    std::cout << "ScalarConvertor assignment operator has been called." << std::endl;
    if (this != &og) 
        *this = og;
    return *this;
}

static void charConv(std::string type)
{
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "char: " << type[0] << std::endl;
    std::cout << "int: ";
    try {
        std::cout << static_cast<int>(type[0]) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "float: ";
    try {
        std::cout << static_cast<float>(type[0]) << "f" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "double: ";
    try {
        std::cout << static_cast<double>(type[0]) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
}

static void intConv(std::string type)
{
    std::cout << std::fixed << std::setprecision(1);
    int nmro = std::stoi(type);

    std::cout << "char: ";
    try {
        if (nmro < 33 || nmro > 126)
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<char>(nmro) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "int: " << nmro << std::endl;
    std::cout << "float: ";
    try {
        std::cout << static_cast<float>(nmro) << "f" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "double: ";
    try {
        std::cout << static_cast<double>(nmro) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
}

static void floatConv(std::string type)
{
    std::cout << std::fixed << std::setprecision(1);
    float nmro = std::stof(type);

    std::cout << "char: ";
    try {
        if (nmro < 33 || nmro > 126 || type == "-inff" || type == "inff" ||
            type == "nan" || type == "inf" || type == "-inf")
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<char>(nmro) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "int: ";
    if (type == "nan" || type == "inff" || type == "-inff")
        std::cout << "impossible" << std::endl;
    else {
        try {
            std::cout << static_cast<int>(nmro) << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "impossible" << std::endl;
        }
    }
    std::cout << "float: " << nmro << "f" << std::endl;
    std::cout << "double: ";
    try {
        std::cout << static_cast<double>(nmro) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
}

static void doubleConv(std::string type)
{
    std::cout << std::fixed << std::setprecision(1);
    double nmro = std::stod(type);

    std::cout << "char: ";
    try {
        if (nmro < 33 || nmro > 126 || type == "-inff" || type == "inff" ||
            type == "nan" || type == "inf" || type == "-inf")
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<char>(nmro) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "int: ";
    if (type == "nan" || type == "inf" || type == "-inf")
        std::cout << "impossible" << std::endl;
    else {
        try {
            std::cout << static_cast<int>(nmro) << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "impossible" << std::endl;
        }
    }
    std::cout << "float: ";
    try {
        std::cout << static_cast<float>(nmro) << "f" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
    std::cout << "double: " << nmro << std::endl;
}



static int checkDigits(std::string strng)
{
    size_t i = 0;
    if (strng.empty())
        return 0;
    if (strng.back() == 'f')
    {
        while (i < strng.length() - 1)
        {
            if (!std::isdigit(strng[i]))
                return 0;
            i++;
        }
    }
    else
    {
        i = 0;
        while (i < strng.length())
        {
            if (!std::isdigit(strng[i]))
                return 0;
            i++;
        }
    }
    return 1;
}

static int getType(std::string strng)
{
    long strngtolong;

	if (strng == "-inff" || strng == "inff" || strng == "nanf")
        return 2;
    if (strng == "-inf" || strng == "inf" || strng == "nan")
        return 3;
    if (strng.find('.') != std::string::npos && strng[strng.find('.') + 1] && !checkDigits(&strng[strng.find('.') + 1]))
        return 4;
    try {
        strngtolong = std::stol(strng);
        if (strngtolong > INT_MAX || strngtolong < INT_MIN)
            return 4;
    }
    catch(const std::exception& e) {
        return 4;
    }
    if (strng.length() == 1 && !std::isdigit(strng[0]))
        return 0;
    if (std::isalpha(strng[0]) && (strng.length() == 1))
        return 0;
    else if (!std::isalpha(strng[0]))
        return 1;
    else if (strng.back() == 'f' && strng.find('.') != std::string::npos)
        return 2;
    else if (strng.find('.') != std::string::npos)
        return 3;
    return 4;
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