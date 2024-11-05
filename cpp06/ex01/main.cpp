/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:13:28 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/05 12:13:28 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data simos;
    Data *ptr = Serializer::deserialize(Serializer::serialize(&simos));
    std::cout << (ptr == &simos) << std::endl;
    return (0);
}