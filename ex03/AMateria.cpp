/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:14:07 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 15:14:08 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria& other) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

AMateria::~AMateria() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}
