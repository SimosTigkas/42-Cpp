/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:13:29 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/27 16:05:06 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
    private:
        int                 fixedvalue;
        static const int    bits=8;
    public:
        Fixed(const int num);
        Fixed(const float nmro);
        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed &new_obj);
        Fixed &operator=(const Fixed &new_obj);
        float   toFloat(void) const;
        int     toInt(void) const;
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

std::ostream &operator << (std::ostream &stream, const Fixed &num);

#endif