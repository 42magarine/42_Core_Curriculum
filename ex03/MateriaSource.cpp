/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:37:02 by mott              #+#    #+#             */
/*   Updated: 2024/09/17 13:09:51 by mott             ###   ########.fr       */
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
	copy_template(other);
	std::cout << YELLOW << "(MateriaSource) Copy constructor called" << RESET << std::endl;
}

MateriaSource::~MateriaSource() {
	delete_template();
	std::cout << YELLOW << "(MateriaSource) Destructor called" << RESET << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		delete_template();
		copy_template(other);
		std::cout << YELLOW << "(MateriaSource) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

// Copies the Materia passed as a parameter and store it in memory so it can be cloned later.
void MateriaSource::learnMateria(AMateria* m) {
	if (m == nullptr) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (_template[i] == nullptr) {
			_template[i] = m;
			// _template[i] = m->clone();
			return;
		}
	}
};

// Returns a new Materia. The latter is a copy of the Materia previously learned by the MateriaSource whose type equals the one passed as parameter. Returns 0 if the type is unknown.
AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; i++) {
		if (_template[i] != nullptr && type == _template[i]->getType()) {
			return _template[i]->clone();
		}
	}
	return nullptr;
};

void MateriaSource::delete_template() {
	for (int i = 0; i < 4; i++) {
		delete _template[i];
		_template[i] = nullptr;
	}
}

void MateriaSource::copy_template(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other._template[i] != nullptr) {
			_template[i] = other._template[i];
		}
	}
}
