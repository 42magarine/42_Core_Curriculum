/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:37:02 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 18:33:17 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << YELLOW << "(MateriaSource) Default constructor called" << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << YELLOW << "(MateriaSource) Copy constructor called" << RESET << std::endl;
}

MateriaSource::~MateriaSource() {
	std::cout << YELLOW << "(MateriaSource) Destructor called" << RESET << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		std::cout << YELLOW << "(MateriaSource) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {

};

AMateria* MateriaSource::createMateria(const std::string& type) {

};
