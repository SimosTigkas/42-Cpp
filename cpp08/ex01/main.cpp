/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:54:36 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/14 12:31:39 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    unsigned int span_size = 10;
    Span sp = Span(span_size);
    unsigned int i = 0;
    while(i < span_size)
    {
		sp.addNumber(rand() % 1000);
        i++;
    }
    sp.printSpan();
    std::cout << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return (0);
}