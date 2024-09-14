/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:21:24 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 15:21:25 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Cure::Cure(const Cure& other) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

Cure::~Cure() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}
