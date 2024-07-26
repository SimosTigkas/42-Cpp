/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:04:30 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/25 22:40:59 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include "Brain.hpp"

class WrongCat: public WrongAnimal
{
    protected:
        Brain *brain;
    public:
        WrongCat(void);
        ~WrongCat(void);
        WrongCat(const WrongCat &a_copy);
        WrongCat &operator=(const WrongCat &og);
        using WrongAnimal::makeSound;
};

#endif