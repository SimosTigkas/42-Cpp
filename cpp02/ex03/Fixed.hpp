/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:01:54 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/28 14:51:05 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int                  fixedvalue;
        static const int     bits=8;
    public:
        Fixed(void);
		Fixed(const int num);
		Fixed(const float numro);
		Fixed(const Fixed &new_obj);
		~Fixed(void);
		Fixed &operator=(const Fixed &original);

		int	            getRawBits(void) const;
		void	        setRawBits(int const raw);
		float	        toFloat(void) const;
		int	            toInt(void) const;
		bool            operator>(const Fixed &nbr);
        bool            operator<(const Fixed &nbr);
        bool            operator<=(const Fixed &nbr);
       	bool            operator>=(const Fixed &nbr);
        bool            operator==(const Fixed &nbr);
        bool            operator!=(const Fixed &nbr);
        Fixed           operator+(const Fixed &nbr);
        Fixed           operator-(const Fixed &nbr);
        Fixed           operator*(const Fixed &nbr);
		Fixed           operator/(const Fixed &nbr);
		Fixed           &operator++(void);
		Fixed           operator++(int);
		Fixed           &operator--(void);
		Fixed           operator--(int);
		static          Fixed& min(Fixed &a, Fixed &b);
		static const    Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed&   max(Fixed &a, Fixed &b);
		static const    Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &nmro);

#endif