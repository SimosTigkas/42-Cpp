/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:01:04 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/24 13:39:23 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
    protected:
        Brain *brain;
    public:
        Dog(void);
        ~Dog(void);
        Dog(const Dog &a_copy);
        Dog &operator=(const Dog &og);
        void makeSound(void) const;
        void *getBrainAddress(void);
};

#endif