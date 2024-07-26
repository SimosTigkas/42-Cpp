/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:34:56 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/26 17:42:31 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
    protected:
        std::string type;
    public:
        AAnimal(void);
        AAnimal(std::string type);
        AAnimal(const AAnimal &a_copy);
        virtual ~AAnimal(void);
        AAnimal  &operator=(const AAnimal &og);
        
        virtual void    makeSound(void) const = 0;
        std::string     getType(void) const;
};

#endif