/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:03:01 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/24 22:06:59 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

# include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon&     _weapon;
    public:
        HumanB(std::string name);
        ~HumanB();

        void    attack(void) const;
        void    setWeapon(Weapon& weapon);
};

#endif