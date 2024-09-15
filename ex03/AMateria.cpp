/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:14:07 by mott              #+#    #+#             */
/*   Updated: 2024/09/15 18:07:43 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {
	std::cout << YELLOW << "(AMateria) Default constructor called with " << _type << RESET << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type) {
	std::cout << YELLOW << "(AMateria) Name constructor called with " << _type << RESET << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
	std::cout << YELLOW << "(AMateria) Copy constructor called with " << _type << RESET << std::endl;
}

AMateria::~AMateria() {
	std::cout << YELLOW << "(AMateria) Destructor called with " << _type << RESET << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		// _type = other._type; // ???
		std::cout << YELLOW << "(AMateria) Copy assignment operator called with " << _type << RESET << std::endl;
	}
	return *this;
}

const std::string& AMateria::getType() const {
	return _type;
};
