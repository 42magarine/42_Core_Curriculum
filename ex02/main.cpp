/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:30:34 by mott              #+#    #+#             */
/*   Updated: 2024/09/12 19:58:17 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// int main() {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	delete j;
// 	delete i;

// 	system("leaks brain");
// 	return 0;
// }

// int main() {
// 	Animal *array[10];

// 	for (int i = 0; i < 10; i++) {
// 		if (i % 2 == 0) {
// 			array[i] = new Cat();
// 		}
// 		else
// 			array[i] = new Dog();
// 	}

// 	for (int i = 0; i < 10; i++) {
// 		delete array[i];
// 	}

// 	system("leaks brain");
// 	return 0;
// }

int main() {
	Dog doggy;
	Dog doggy_copy = doggy;

	std::cout << doggy.getBrain() << " " << doggy.getBrain()->getIdeas(0) << std::endl;
	std::cout << doggy_copy.getBrain() << " " << doggy_copy.getBrain()->getIdeas(0) << std::endl;

	doggy.getBrain()->setIdeas(0, "food");

	std::cout << doggy.getBrain() << " " << doggy.getBrain()->getIdeas(0) << std::endl;
	std::cout << doggy_copy.getBrain() << " " << doggy_copy.getBrain()->getIdeas(0) << std::endl;

	Cat *catty = new Cat();
	Cat *catty_copy = catty;

	std::cout << catty->getBrain() << " " << catty->getBrain()->getIdeas(0) << std::endl;
	std::cout << catty_copy->getBrain() << " " << catty_copy->getBrain()->getIdeas(0) << std::endl;

	catty->getBrain()->setIdeas(0, "chill");

	std::cout << catty->getBrain() << " " << catty->getBrain()->getIdeas(0) << std::endl;
	std::cout << catty_copy->getBrain() << " " << catty_copy->getBrain()->getIdeas(0) << std::endl;

	delete catty;

	// system("leaks brain");
	return 0;
}

// int main() {
// 	AAnimal animaly;

// 	std::cout << animaly.getType() << std::endl;
// 	animaly.makeSound();

// 	return 0;
// }
