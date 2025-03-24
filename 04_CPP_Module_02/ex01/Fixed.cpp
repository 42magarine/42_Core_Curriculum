/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:42:45 by mott              #+#    #+#             */
/*   Updated: 2024/08/31 14:19:50 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point_number(0) {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int int_number) {
	std::cout << YELLOW << "Int constructor called" << RESET << std::endl;
	_fixed_point_number = int_number << _fractional_bits;
}

Fixed::Fixed(const float float_number) {
	std::cout << YELLOW << "Float constructor called" << RESET << std::endl;
	_fixed_point_number = std::roundf(float_number * (1 << _fractional_bits));
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
	return _fixed_point_number;
}

void Fixed::setRawBits(const int raw) {
	_fixed_point_number = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_fixed_point_number) / (1 << _fractional_bits);
}

int Fixed::toInt() const {
	return _fixed_point_number >> _fractional_bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
