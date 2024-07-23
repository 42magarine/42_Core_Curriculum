/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:26:43 by mott              #+#    #+#             */
/*   Updated: 2024/07/23 15:26:44 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Default constructor
Fixed::Fixed() {
	// Initialization code
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
	// Copy initialization code
	std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) { // self-assignment check
		// Copy assignment code
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

// Destructor
Fixed::~Fixed() {
	// Cleanup code
	std::cout << "Destructor called" << std::endl;
}
