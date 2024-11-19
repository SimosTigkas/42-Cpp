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

/*
• Your program must take a file as argument.
• Each line in this file must use the following format: "date | value".
• A valid date will always be in the following format: Year-Month-Day.
• A valid value must be either a float or a positive integer, between 0 and 1000.
• Your program should display on the standard output the result of the value multiplied
by the exchange rate according to the date indicated in your database.
*/


int main(int ac, char **av)
{
    std::ifstream   infile;
    std::ofstream   outfile;
    std::string     buffer;
    size_t          exists;

    if (ac != 2)
    {
        std::cout << "I need one argument: <filename>" << std::endl;
        return (1);
    }
    infile.open(av[1], std::ios::in);
    if (!infile.is_open())
    {
        std::cout << "Error while trying to open the file\n" << std::endl;
        return (42);
    }
    while (getline(infile, buffer))
    {
        if ((exists = buffer.find(av[1])) == std::string::npos)
            outfile << buffer << std::endl;
        else 
        {
            while ((exists = buffer.find(av[2])) != std::string::npos)
            {
                //something   
            }
            outfile << buffer << std::endl;
        }
    }
    outfile.close();
    infile.close();
    return (0);
}