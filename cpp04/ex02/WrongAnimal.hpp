/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:06:37 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/25 22:40:49 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal(void);
        WrongAnimal(std::string name);
        WrongAnimal(const WrongAnimal &a_copy);
        virtual ~WrongAnimal(void);
        WrongAnimal  &operator=(const WrongAnimal &og);
        
        virtual void    makeSound(void) const;
        std::string     getType(void) const;
};

#endif