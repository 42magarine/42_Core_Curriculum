/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:28:38 by mott              #+#    #+#             */
/*   Updated: 2024/09/12 14:36:05 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main() {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;

// 	i->makeSound();
// 	j->makeSound();
// 	meta->makeSound();

// 	delete meta;
// 	delete j;
// 	delete i;

// 	// system("leaks animal");
// 	return 0;
// }

int main() {
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();

	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	meta->makeSound();

	delete meta;
	delete i;

	// system("leaks animal");
	return 0;
}
