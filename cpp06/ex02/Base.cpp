/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:51:52 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/07 12:24:41 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void) {}

Base *generate(void)
{
    int nmro;

    std::srand(std::time(0));
    nmro = rand() % 5;
    if (nmro == 3)
        return new A;
    else if (nmro == 4)
        return new B;
    else
        return new C;
}

void identify(Base *p)
{
    
}

void identify(Base &p)
{
    
}