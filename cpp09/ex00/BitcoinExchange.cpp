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

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& a_copy) {
    *this = a_copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& og) {
    if (this != &og)
        _rates = og._rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const std::map<std::string, double>& rates): _rates(rates) {}