/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:59:42 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/26 17:16:42 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
    protected:
        Brain *brain;
    public:
        Cat(void);
        ~Cat(void);
        Cat(const Cat &a_copy);
        Cat &operator=(const Cat &og);
        virtual void makeSound(void) const override;
        void getIdeas(void) const;
        void setIdea(int i, std::string idea);
};

#endif