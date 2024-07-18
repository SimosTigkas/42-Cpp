/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:38 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/18 13:14:50 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    private:
        ScavTrap(void);
    public:
        ScavTrap(std::string name);
		ScavTrap(const ScavTrap &a_copy);
		ScavTrap& operator=(const ScavTrap &og);
		~ScavTrap(void);

        void attack(const std::string& target);
        void guardGate(void);
};

#endif