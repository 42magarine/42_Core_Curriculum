/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:31:53 by mott              #+#    #+#             */
/*   Updated: 2024/08/23 14:54:44 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), _pointer(new Brain()) {
	_type = "dog";
	std::cout << "Dog default constructor..." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _pointer(new Brain(*other._pointer)) {
	// _type = "dog";
	std::cout << "Dog copy constructor..." << std::endl;
}

Dog::~Dog() {
	delete _pointer;
	std::cout << "Dog destructor..." << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		*_pointer = *other._pointer;
	}
	std::cout << "Dog copy assignment operator..." << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "I'm a dog." << std::endl;
}
