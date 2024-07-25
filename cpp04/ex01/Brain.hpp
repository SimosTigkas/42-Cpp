/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:05:33 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/25 13:53:55 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        virtual ~Brain();
        Brain(const Brain &a_copy);
        Brain &operator=(const Brain &og);
        const std::string *getIdeaAddress(int i) const;
        const std::string getIdea(int i) const;
        void  setIdea(int i, std::string idea);
};

#endif