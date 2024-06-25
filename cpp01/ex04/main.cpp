/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:55:41 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/25 14:55:41 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
    std::ifstream   infile;
    std::ofstream   outfile;
    std::string     buffer;
    size_t          exists;

    if (ac != 4)
    {
        std::cout << "I need three arguments: <filename>, <string_1> and <string_2>" << std::endl;
        return (1);
    }
    if (std::string(av[2]).empty())
    {
        std::cout << "The string that will be replaced cannot be empty!" << std::endl;
        return (1);
    }
    if ((std::string(av[2]).compare(std::string(av[3]))) == 0)
    {
        std::cout << "The string we want to replace cannot be the same as the one we want to replace it with.." << std::endl;
        return (1);
    }

    infile.open(av[1], std::ios::in);
    if (!infile.is_open())
    {
        std::cout << "Error while trying to open the file\n" << std::endl;
        return (42);
    }
    outfile.open((std::string(av[1]) + ".replace").c_str());
    if (!outfile.is_open())
    {
        std::cout << "Error while trying to create the replacement file\n" << std::endl;
        return (24);
    }
    while (getline(infile, buffer))
    {
        if ((exists = buffer.find(av[2])) == std::string::npos)
            outfile << buffer << std::endl;
        else 
        {
            while ((exists = buffer.find(av[2])) != std::string::npos)
            {
                outfile << buffer.substr(0, exists) + (std::string)av[3];
                buffer = buffer.substr(exists + ((std::string)av[2]).length());
            }
            outfile << buffer << std::endl;
        }
    }
    outfile.close();
    infile.close();
    return (0);
}