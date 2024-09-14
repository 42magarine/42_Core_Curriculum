/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:14:07 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 19:19:19 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << YELLOW << "(AMateria) Default constructor called" << RESET << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type) {
	std::cout << YELLOW << "(AMateria) Name constructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
	std::cout << YELLOW << "(AMateria) Copy constructor called" << RESET << std::endl;
}

AMateria::~AMateria() {
	std::cout << YELLOW << "(AMateria) Destructor called" << RESET << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		_type = other._type;
		std::cout << YELLOW << "(AMateria) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
} // delete old object first?

const std::string& AMateria::getType() const {
	return _type;
};

// void AMateria::use(ICharacter& target) {
// 	std::cout << "* " << target.getName() << " *" << std::endl;
// };
