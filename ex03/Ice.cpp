/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:21:29 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 21:10:15 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << YELLOW << "(Ice) Default constructor called" << RESET << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << YELLOW << "(Ice) Copy constructor called" << RESET << std::endl;
}

Ice::~Ice() {
	std::cout << YELLOW << "(Ice) Destructor called" << RESET << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other) {
		AMateria::operator=(other);
		std::cout << YELLOW << "(Ice) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

AMateria* Ice::clone() const{
	return new Ice();
};

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
};
