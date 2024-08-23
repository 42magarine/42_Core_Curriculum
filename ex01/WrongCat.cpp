/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:46:41 by mott              #+#    #+#             */
/*   Updated: 2024/08/23 13:47:24 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	_type = "cat";
	std::cout << "WrongCat default constructor..." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	_type = "cat";
	std::cout << "WrongCat copy constructor..." << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor..." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout << "WrongCat copy assignment operator..." << std::endl;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "I'm a wrong cat." << std::endl;
}
