/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:31:46 by mott              #+#    #+#             */
/*   Updated: 2024/08/22 18:14:04 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	_type = "cat";
	std::cout << "Cat default constructor..." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	_type = "cat";
	std::cout << "Cat copy constructor..." << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor..." << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "Cat copy assignment operator..." << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "I'm a cat." << std::endl;
}
