/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:21:24 by mott              #+#    #+#             */
/*   Updated: 2024/09/17 13:03:26 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << YELLOW << "(Cure) Default constructor called with " << this->getType() << RESET << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	std::cout << YELLOW << "(Cure) Copy constructor called with " << this->getType() << RESET << std::endl;
}

Cure::~Cure() {
	std::cout << YELLOW << "(Cure) Destructor called with " << this->getType() << RESET << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		AMateria::operator=(other);
		std::cout << YELLOW << "(Cure) Copy assignment operator called with " << this->getType() << RESET << std::endl;
	}
	return *this;
}

// Of course, their member function clone() will return a new instance of the same type.
AMateria* Cure::clone() const {
	return new Cure(*this);
};

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
};
