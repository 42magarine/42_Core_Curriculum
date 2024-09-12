/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:44:19 by mott              #+#    #+#             */
/*   Updated: 2024/09/12 15:44:00 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("animal") {
	std::cout << YELLOW << "(WrongAnimal) Default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
	std::cout << YELLOW << "(WrongAnimal) Copy constructor called" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << YELLOW << "(WrongAnimal) Destructor called" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		_type = other._type;
		std::cout << YELLOW << "(WrongAnimal) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "I'm an animal." << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}
