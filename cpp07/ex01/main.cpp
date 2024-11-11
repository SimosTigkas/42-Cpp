/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:14:40 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/07 14:14:40 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    double      aperture[] = {1.4 , 2.0, 2.8, 4.0, 5.6, 8.0, 11.0, 16.0};
    std::string camera[] = {"Sony", "Canon", "Fujifilm", "Nikon"};

    iter(aperture, 8, &ft_print);
    std::cout << std::endl;
    iter(camera, 4, &ft_print); 
}