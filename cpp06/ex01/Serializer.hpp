/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:10:55 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/05 12:10:55 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <cstdint> 
#include "Data.hpp"


class Serializer
{
    private:
        Serializer(void);
        ~Serializer(void);
        Serializer(const Serializer &a_copy);
        Serializer& operator=(const Serializer &og);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif