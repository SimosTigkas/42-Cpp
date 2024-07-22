/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:15 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/22 13:53:33 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    private:
        FragTrap(void);
    public:
        FragTrap(std::string name);
		FragTrap(const FragTrap &a_copy);
		FragTrap& operator=(const FragTrap &og);
		~FragTrap(void);

        void attack(const std::string& target);
        void highFivesGuys(void);};

#endif