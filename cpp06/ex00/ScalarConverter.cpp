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
    if (type.length() == 1 && std::isprint(type[0]))
        std::cout << "char: '" << type[0] << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

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
    try {
        int nmro = std::stoi(type);
        if (nmro > INT_MAX || nmro < INT_MIN)
            throw std::out_of_range("Value exceeds int range");
        std::cout << "char: ";
        if (nmro < 0 || nmro > 255)
            std::cout << "impossible" << std::endl;
        else if (!std::isprint(static_cast<char>(nmro)))
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(nmro) << "'" << std::endl;
        std::cout << "int: " << nmro << std::endl;
        std::cout << "float: " << static_cast<float>(nmro) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(nmro) << std::endl;
    }
    catch (...) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

static void floatConv(std::string type)
{
    std::cout << std::fixed << std::setprecision(1);
    float nmro = std::stof(type);

    std::cout << "char: ";
    try {
        if (nmro < 33 || nmro > 126 || type == "-inff" || type == "inff" || type == "nanf" || type == "-nanf")
            std::cout << "impossible" << std::endl;
        else
            std::cout << "'" << static_cast<char>(nmro) << "'" << std::endl;
        std::cout << "int: ";
        if (nmro < static_cast<float>(INT_MIN) || nmro > static_cast<float>(INT_MAX))
            std::cout << "impossible" << std::endl;
        else if (type == "nanf" || type == "inff" || type == "-inff" || type == "-nanf")
        {
            std::cout << "impossible" << std::endl;
            std::cout << "float: " << type << std::endl;
            std::cout << "double: " << type.substr(0, type.size() - 1) << std::endl;
            return;
        }
        else
            std::cout << static_cast<int>(nmro) << std::endl;
        std::cout << "float: " << nmro << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(nmro) << std::endl;
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
        if (nmro < 33 || nmro > 126 || type == "nan" || type == "inf" || type == "-inf" || type == "-nan")
            std::cout << "impossible" << std::endl;
        else
            std::cout << "'" << static_cast<char>(nmro) << "'" << std::endl;
        std::cout << "int: ";
        if (nmro < static_cast<double>(INT_MIN) || nmro > static_cast<double>(INT_MAX))
            std::cout << "impossible" << std::endl;
        else if (type == "nan" || type == "inf" || type == "-inf" || type == "-nan")
        {
            std::cout << "impossible" << std::endl;
            std::cout << "float: " << type << "f" << std::endl;
            std::cout << "double: " << type << std::endl;
            return;
        }
        else
            std::cout << static_cast<int>(nmro) << std::endl;
        std::cout << "float: " << static_cast<float>(nmro) << "f" << std::endl;
        std::cout << "double: " << nmro << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
}

static int getType(std::string strng)
{
    std::regex validInputPattern(R"(^[+-]?(\d+(\.\d*)?|\.\d+|nan|inf|(\d+(\.\d*)?[eE][+-]?\d+))(f)?)");
    if (strng.length() == 1 && std::isprint(strng[0]) && !std::isdigit(strng[0]))
            return 0;
    if (!std::regex_match(strng, validInputPattern))
        return 4;
    else {
	    if (strng == "-inff" || strng == "inff" || strng == "nanf" || strng == "-nanf")
            return 2;
        if (strng == "-inf" || strng == "inf" || strng == "nan" || strng == "-nan")
            return 3;
        if (strng.find('.') != std::string::npos)
            return strng.back() == 'f' ? 2 : 3;
        if (strng.find('e') != std::string::npos || strng.find('E') != std::string::npos)
            return strng.back() == 'f' ? 2 : 3;
        try {
            long long strngtolong = std::stoll(strng);
            if (strngtolong > INT_MAX || strngtolong < INT_MIN)
                return 4;
        }
        catch (...)
        {
            return 4;
        }
    }
    try {
        int intValue = std::stoi(strng);
        (void)intValue;
        return 1;
    }
    catch (...) {
        return 4;
    }
    return 4;
}

void ScalarConverter::convert(std::string type)
{
    try
    {
        void (*differentTypes[4])(std::string) = {&charConv, &intConv, &floatConv, &doubleConv};
        size_t decimalCount = std::count(type.begin(), type.end(), '.');
        type.erase(0, type.find_first_not_of(" "));
        type.erase(type.find_last_not_of(" ") + 1);
        if (getType(type) == 4 || decimalCount > 1)
            throw std::invalid_argument("Invalid input");
        differentTypes[getType(type)](type);
    }
    catch(...)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
