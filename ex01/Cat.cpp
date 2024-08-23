/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:31:46 by mott              #+#    #+#             */
/*   Updated: 2024/08/23 14:57:29 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(), _pointer(new Brain()) {
	_type = "cat";
	std::cout << "Cat default constructor..." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), _pointer(new Brain(*other._pointer)) {
	// _type = "cat";
	std::cout << "Cat copy constructor..." << std::endl;
}

Cat::~Cat() {
	delete _pointer;
	std::cout << "Cat destructor..." << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		*_pointer = *other._pointer;
	}
	std::cout << "Cat copy assignment operator..." << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "I'm a cat." << std::endl;
}
