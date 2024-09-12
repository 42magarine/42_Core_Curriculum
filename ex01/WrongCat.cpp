/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:46:41 by mott              #+#    #+#             */
/*   Updated: 2024/09/12 15:44:25 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	_type = "Cat";
	std::cout << YELLOW << "(WrongCat) Default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << YELLOW << "(WrongCat) Copy constructor called" << RESET << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << YELLOW << "(WrongCat) Destructor called" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
		std::cout << YELLOW << "(WrongCat) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "I'm a wrong cat." << std::endl;
}
