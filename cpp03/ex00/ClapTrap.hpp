/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:17:55 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/12 11:34:54 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    public:
        ClapTrap(std::string name);
        ~ClapTrap(void);
        ClapTrap(const ClapTrap &a_copy);
        ClapTrap& operator=(const ClapTrap &og);
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    protected:
        std::string          name;
        unsigned int         hitPoints;
        unsigned int         energyPoints;
        unsigned int         attackDamage;
};

#endif