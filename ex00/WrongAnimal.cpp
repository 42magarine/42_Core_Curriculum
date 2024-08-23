/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:44:19 by mott              #+#    #+#             */
/*   Updated: 2024/08/23 13:45:17 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("animal") {
	std::cout << "WrongAnimal default constructor..." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
	std::cout << "WrongAnimal copy constructor..." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor..." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "WrongAnimal copy assignment operator..." << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "I'm an animal." << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}
