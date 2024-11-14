/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:53:29 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/14 11:13:45 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <cmath>

class Span {
    private:
        unsigned int     size;
        std::vector<int> vec;
    public:
        Span(void);
        Span(unsigned int nmro);
        Span(const Span &a_copy);
        Span& operator=(const Span &og);
        ~Span(void);
        void     addNumber(int nmro);
        int      shortestSpan(void) const;
        int      longestSpan(void) const;
        class VecIsTooSmallException : public std::exception {
            public:
                const char *what() const throw()
                {
                    const char *err = "The amount of elements at the vector are not enough to create a span.";
                    return (err);
                }
        };
        class VecIsFullException : public std::exception {
            public:
                const char *what() const throw()
                {
                    const char *err = "The vector is already filled with the desired amount of numbers.";
                    return (err);
                }                
        };
};

#endif