/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:37:02 by mott              #+#    #+#             */
/*   Updated: 2024/09/15 17:15:34 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		_template[i] = nullptr;
	}
	std::cout << YELLOW << "(MateriaSource) Default constructor called" << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		_template[i] = other._template[i]; // deep copy?
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
	if (m == nullptr) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (_template[i] == nullptr) {
			_template[i] = m;
			return;
		}
	}
};

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; i++) {
		if (_template[i] != nullptr && type == _template[i]->getType()) {
			return _template[i]->clone();
		}
	}
	return nullptr;
};
