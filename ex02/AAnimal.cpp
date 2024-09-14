/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:31:41 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 16:24:40 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("animal") {
	std::cout << YELLOW << "(AAnimal) Default constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
	std::cout << YELLOW << "(AAnimal) Copy constructor called" << RESET << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << YELLOW << "(AAnimal) Destructor called" << RESET << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this != &other) {
		_type = other._type;
		std::cout << YELLOW << "(AAnimal) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

std::string AAnimal::getType() const {
	return _type;
}
