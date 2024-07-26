/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:34:56 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/26 17:20:16 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTANIMAL_HPP
# define ABSTRACTANIMAL_HPP

# include <iostream>
# include <string>

class AbstractAnimal
{
    protected:
        std::string type;
    public:
        AbstractAnimal(void);
        AbstractAnimal(std::string type);
        AbstractAnimal(const AbstractAnimal &a_copy);
        virtual ~AbstractAnimal(void);
        AbstractAnimal  &operator=(const AbstractAnimal &og);
        
        virtual void    makeSound(void) const = 0;
        std::string     getType(void) const;
};

#endif