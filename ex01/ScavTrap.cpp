/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:30:16 by mott              #+#    #+#             */
/*   Updated: 2024/08/21 14:30:50 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() {
	std::cout << "Default constructor called" << std::endl;
	// Initialization code
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) {
	std::cout << "Copy constructor called" << std::endl;
	// Copy initialization code
}

// Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	// self-assignment check
	if (this != &other) {
		std::cout << "Copy assignment operator called" << std::endl;
		// Copy assignment code
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "Destructor called" << std::endl;
	// Cleanup code
}
