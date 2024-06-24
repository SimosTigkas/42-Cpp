/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:19:17 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/24 15:22:34 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <stdio.h>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		~Zombie();

		void setName(std::string name);
		const std::string& getName(void) const;

		void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
