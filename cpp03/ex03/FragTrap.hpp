/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:18:44 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/22 15:21:11 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
		FragTrap(const FragTrap &a_copy);
		FragTrap& operator=(const FragTrap &og);
		~FragTrap(void);

        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
