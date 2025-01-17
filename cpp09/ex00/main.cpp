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

static void checkLine(std::string &line)
{
    std::string date;
    std::istringstream iss(line);
    std::regex dateFormat(R"((\d{4})-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01]))");
    iss >> date;
    if (std::regex_match(date, dateFormat))
        return ;
    else
        throw std::runtime_error("Error: wrong date input -> " + date);
}

static void checkFile(const std::string &file, const BitcoinExchange &bitcoin)
{
    std::ifstream infile(file);
    std::string line;
    std::regex linePattern(R"((\d{4})-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01]) \| (-?\d+(\.\d+)?))");
    std::smatch match_result;
    bool lineIsValid = false;
    std::string date;
    std::string strValue;
    double value;
    double rate;

    if (!infile.is_open()) throw std::runtime_error("Error while trying to open the file\n");
    if (std::getline(infile, line))
    {
        if (line != "date | value")
            throw std::runtime_error("The header should be like this: date | value");
    }
    else
        throw std::runtime_error("Error: The file is empty..");
    while (std::getline(infile, line))
    {
        try
        {
            checkLine(line);
            if (std::regex_match(line, match_result, linePattern))
            {
                lineIsValid = true;
                date = match_result[1].str() + "-" + match_result[2].str() + "-" + match_result[3].str();
                strValue = match_result[4];
                value = std::stod(strValue);
                if (value <0 || value > 10000)
                    throw std::runtime_error("The value does not belong to this: [0,1000]");
                rate = bitcoin.getRate(date);
                std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
            }
            else
                throw std::runtime_error("Error: Wrong line format -> " + line);
        }
        catch (std::exception &e)
        {
            std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;    
        }
    }
    if (!lineIsValid)
        std::cerr << "No valid lines found in the file" <<std::endl;
}

std::map<std::string, double> checkDatabase(const std::string &file)
{
    std::ifstream infile(file);
    std::string date;
    std::map<std::string, double> exRates;
    std::string line;
    double rate;
    size_t pos;

    if (!infile.is_open())
        throw std::runtime_error("Error while trying to open the file");
    std::getline(infile, line);
    while (std::getline(infile, line))
    {
        pos = line.find(',');
        if (pos == std::string::npos)
            throw std::runtime_error("Error while trying to locate a comma in " + line);
        date = line.substr(0, pos);
        rate = std::stod(line.substr(pos + 1));
        exRates[date] = rate;
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