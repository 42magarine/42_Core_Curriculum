/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:30:34 by mott              #+#    #+#             */
/*   Updated: 2024/08/23 16:09:34 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// int main() {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	delete j;//should not create a leak
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

// 	delete[] array;
// }

int main() {
	Dog doggy;
	Dog doggy_copy = doggy;

	std::cout << doggy._pointer << " " << doggy._pointer->_ideas[0] << std::endl;
	std::cout << doggy_copy._pointer << " " << doggy_copy._pointer->_ideas[0] << std::endl;

	doggy._pointer->_ideas[0] = "food";

	std::cout << doggy._pointer << " " << doggy._pointer->_ideas[0] << std::endl;
	std::cout << doggy_copy._pointer << " " << doggy_copy._pointer->_ideas[0] << std::endl;

	Cat *catty = new Cat();
	Cat *catty_copy = catty;

	std::cout << catty->_pointer << " " << catty->_pointer->_ideas[0] << std::endl;
	std::cout << catty_copy->_pointer << " " << catty_copy->_pointer->_ideas[0] << std::endl;

	catty->_pointer->_ideas[0] = "chill";

	std::cout << catty->_pointer << " " << catty->_pointer->_ideas[0] << std::endl;
	std::cout << catty_copy->_pointer << " " << catty_copy->_pointer->_ideas[0] << std::endl;

	delete catty;
}
