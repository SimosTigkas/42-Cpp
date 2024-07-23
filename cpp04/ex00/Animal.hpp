/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:34:56 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/23 12:52:33 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal(void);
        Animal(std::string name);
        Animal(const Animal &a_copy);
        virtual ~Animal(void);
        Animal  &operator=(const Animal &og);
        
        virtual void    makeSound(void) const;
        std::string     getType(void) const;

};

#endif