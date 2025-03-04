/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:57:19 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/18 21:57:19 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
    // std::cout << "BitcoinExchange Default Constructor has been called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& a_copy) {
    // std::cout << "BitcoinExchange Copy Constructor has been called" <<std::endl;
    *this = a_copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& og) {
// std::cout << "BitcoinExchange assignment operator has been called." << std::endl;
    if (this != &og)
        _rates = og._rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) {
    // std::cout << "BitcoinExchange Destructor has been called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::map<std::string, double> &rates)
{
    // std::cout << "BitcoinExchange parameterized Constructor has been called" << std::endl;
    _rates = rates;
}

double BitcoinExchange::getRate(const std::string& date) const
{
    if (_rates.empty())
        throw std::runtime_error("Error: No rates available");
    std::map<std::string, double>::const_iterator i = _rates.lower_bound(date);
    if (i == _rates.begin() && i->first != date)
        throw std::runtime_error("Error: Date not found");
    if (i == _rates.end() || i->first != date)
        i--;
    return i->second;
}