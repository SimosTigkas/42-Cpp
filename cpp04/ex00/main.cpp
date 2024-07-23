/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 08:03:38 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/23 13:51:40 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal	*meta = new Animal();
	std::cout << "Animal type: " << meta->getType() << std::endl;
	meta->makeSound();
	delete meta;
	std::cout << std::endl;

	const Animal	*kissa = new Cat();
	std::cout << "Cat type: " << kissa->getType() << std::endl;
	kissa->makeSound();
	delete kissa;

	const Animal	*koira = new Dog();
	std::cout << "Dog type: " << koira->getType() << std::endl;
	koira->makeSound();
	delete koira;

	const WrongAnimal	*wrong_meta = new WrongAnimal();
	std::cout << "Animal type: " << wrong_meta->getType() << std::endl;
	wrong_meta->makeSound();
	delete wrong_meta;

	const WrongAnimal	*wrong_kissa = new WrongCat();
	std::cout << "WrongCat type: " << wrong_kissa->getType() << std::endl;
	wrong_kissa->makeSound();
	delete wrong_kissa;
    return 0;
}