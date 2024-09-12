/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:16:35 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/04 13:16:35 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(std::string const &type);
        AMateria(void);
        AMateria(const AMateria &type_to_copy);
        virtual ~AMateria(void);
        AMateria& operator=(const AMateria& og);
        std::string const   &getType() const;
        virtual AMateria    *clone() const = 0;
        virtual void        use(ICharacter& target);
};




#endif