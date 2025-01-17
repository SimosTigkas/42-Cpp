/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:56:21 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/18 21:56:21 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
#include <sstream>
# include <string>
# include <map>
# include <regex>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _rates;
    public:
        BitcoinExchange(void);
        BitcoinExchange(const std::map<std::string, double>& rates);
        ~BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &a_copy);
        BitcoinExchange &operator=(const BitcoinExchange &og);
        double getRate(const std::string &date) const;
};

std::map<std::string, double> checkDatabase(const std::string &file);

#endif