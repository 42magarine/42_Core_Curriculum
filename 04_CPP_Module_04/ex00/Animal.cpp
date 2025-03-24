/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:31:41 by mott              #+#    #+#             */
/*   Updated: 2024/09/12 13:42:51 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("animal") {
	std::cout << YELLOW << "(Animal) Default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
	std::cout << YELLOW << "(Animal) Copy constructor called" << RESET << std::endl;
}

Animal::~Animal() {
	std::cout << YELLOW << "(Animal) Destructor called" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		_type = other._type;
		std::cout << YELLOW << "(Animal) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

void Animal::makeSound() const {
	std::cout << "I'm an animal." << std::endl;
}

std::string Animal::getType() const {
	return _type;
}
