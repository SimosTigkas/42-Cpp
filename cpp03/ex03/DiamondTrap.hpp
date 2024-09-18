/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:00 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/16 10:57:25 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    public:
        DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &a_copy);
		DiamondTrap& operator=(const DiamondTrap &og);
		~DiamondTrap(void);
    using ScavTrap::attack;
        void whoAmI(void);
    protected:
        std::string name;
        unsigned int         hitPoints;
        unsigned int         energyPoints;
        unsigned int         attackDamage;
    // DiamondTrap(void);        
};

#endif