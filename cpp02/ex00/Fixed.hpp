/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:48:30 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/26 18:48:30 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int                 value;
        static const int    bits=8;
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed &value_copy);
        Fixed &operator=(const Fixed &original);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif