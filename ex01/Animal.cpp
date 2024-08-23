/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:31:41 by mott              #+#    #+#             */
/*   Updated: 2024/08/22 18:27:06 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("animal") {
	std::cout << "Animal default constructor..." << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
	std::cout << "Animal copy constructor..." << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor..." << std::endl;
}

Animal& Animal::operator=(const Animal &other) {
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "Animal copy assignment operator..." << std::endl;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "I'm an animal." << std::endl;
}

std::string Animal::getType() const {
	return _type;
}
