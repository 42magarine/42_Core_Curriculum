/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:31:53 by mott              #+#    #+#             */
/*   Updated: 2024/09/12 19:58:01 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal(), _pointer(new Brain()) {
	_type = "Dog";
	std::cout << YELLOW << "(Dog) Default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), _pointer(new Brain(*other._pointer)) {
	std::cout << YELLOW << "(Dog) Copy constructor called" << RESET << std::endl;
}

Dog::~Dog() {
	delete _pointer;
	std::cout << YELLOW << "(Dog) Destructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		AAnimal::operator=(other);
		*_pointer = *other._pointer;
		std::cout << YELLOW << "(Dog) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
	return _pointer;
}
