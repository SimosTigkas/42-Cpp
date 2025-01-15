/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:38:54 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/18 17:38:54 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static void checkFile(const std::string &file, const BitcoinExchange &bitcoin)
{
    //tomorrow
    (void)file;
    (void)bitcoin;
}

static std::map<std::string, double> checkDatabase(const std::string& file)
{
    std::ifstream infile(file);
    std::string line;
    std::string date;
    double value;
    infile.open(file, std::ios::in);
    if (!infile.is_open()) throw std::runtime_error("Error while trying to open the file\n");
    std::map<std::string, double> exRates;
    std::getline(infile, line);
    while (getline(infile, line))
    {
        size_t pos = line.find(",");
        if (pos == std::string::npos) throw std::runtime_error("Error while trying to locate a comma in " + line);
        date = line.substr(0, pos);
        value = std::stod(line.substr(pos + 1));
        if (!value) throw std::runtime_error("Conversion failed");
        exRates[date] = value;
    }
    return exRates;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Try this: ./btc <filename>" << std::endl;
        return (1);
    }
    try {
        std::map<std::string, double> exRates = checkDatabase("data.csv");
        BitcoinExchange bitcoin(exRates);
        checkFile(av[1], bitcoin);
    }  
    catch (std::exception &e)
    {
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}
    return (0);
}