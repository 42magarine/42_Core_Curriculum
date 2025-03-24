/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:31:53 by mott              #+#    #+#             */
/*   Updated: 2024/09/12 15:34:12 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	_type = "Dog";
	std::cout << YELLOW << "(Dog) Default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << YELLOW << "(Dog) Copy constructor called" << RESET << std::endl;
}

Dog::~Dog() {
	std::cout << YELLOW << "(Dog) Destructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		std::cout << YELLOW << "(Dog) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
