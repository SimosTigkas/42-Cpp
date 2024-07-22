/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:49 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/22 15:15:21 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
		ScavTrap(const ScavTrap &a_copy);
		ScavTrap& operator=(const ScavTrap &og);
		~ScavTrap(void);

        void attack(const std::string& target);
        void guardGate(void);
};

#endif
