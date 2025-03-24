/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:42:45 by mott              #+#    #+#             */
/*   Updated: 2024/08/31 14:08:34 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point_number(0) {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& other) : _fixed_point_number(other.getRawBits()) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

Fixed::~Fixed() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
		_fixed_point_number = other.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixed_point_number;
}

void Fixed::setRawBits(const int raw) {
	std::cout <<  "setRawBits member function called" << std::endl;
	_fixed_point_number = raw;
}
