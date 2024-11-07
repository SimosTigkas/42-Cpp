/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:52:14 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/07 13:45:35 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
    
    Base *ptr = generate();
    Base &ref = *ptr;

    identify(ptr);
    identify(ref);
    return (0);
}