/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:31:46 by mott              #+#    #+#             */
/*   Updated: 2024/09/12 14:14:02 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	std::cout << YELLOW << "(Cat) Default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	_type = "Cat";
	std::cout << YELLOW << "(Cat) Copy constructor called" << RESET << std::endl;
}

Cat::~Cat() {
	std::cout << YELLOW << "(Cat) Destructor called" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		std::cout << YELLOW << "(Cat) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
