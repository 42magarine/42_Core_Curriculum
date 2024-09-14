/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:37:02 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 21:21:00 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	// pointer auf null setzen?!
	std::cout << YELLOW << "(MateriaSource) Default constructor called" << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		_slot[i] = other._slot[i]; // deep copy?
	}
	std::cout << YELLOW << "(MateriaSource) Copy constructor called" << RESET << std::endl;
}

MateriaSource::~MateriaSource() {
	std::cout << YELLOW << "(MateriaSource) Destructor called" << RESET << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		// deep copy?
		std::cout << YELLOW << "(MateriaSource) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	_slot[0] = m;
	_slot[1] = m;
	_slot[2] = m;
	_slot[3] = m;
};

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; i++) {
		if (type == _slot[i]->getType()) {
			return _slot[i]->clone();
		}
	}
	return nullptr;
	// (void)type;
	// return _slot[0]->clone();
};
