/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:51:52 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/07 13:45:39 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {}

Base* generate(void)
{

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 4);

    int nmro = dis(gen);

    if (nmro == 3)
        return new A;
    else if (nmro == 4)
        return new B;
    else
        return new C;
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try {
        (void) dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception &e) {}

    try {
        (void) dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } catch (std::exception &e) {}

    try {
        (void) dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (std::exception &e) {}
}
