/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:15 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/19 16:10:30 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "ClapTrap.hpp"

class FlagTrap: public ClapTrap
{
    private:
        FlagTrap(void);
    public:
        FlagTrap(std::string name);
		FlagTrap(const FlagTrap &a_copy);
		FlagTrap& operator=(const FlagTrap &og);
		~FlagTrap(void);

        void attack(const std::string& target);
        void highFivesGuys(void);};

#endif