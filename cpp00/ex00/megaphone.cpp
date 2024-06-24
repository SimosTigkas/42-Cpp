/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:18:26 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/24 12:17:16 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static void print_ft_upper(char **av)
{
	int i = 1;
	while (av[i])
	{
		int j = 0;
		while (av[i][j])
		{
			std::cout << (char)toupper(av[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
}


int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		print_ft_upper((char **)av);
	return (0);
}
