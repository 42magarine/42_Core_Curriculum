/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:42:45 by mott              #+#    #+#             */
/*   Updated: 2024/07/23 21:01:30 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixed_point_number(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_number) {
	std::cout << "Int constructor called" << std::endl;
	_fixed_point_number = int_number << _fractional_bits;
}

Fixed::Fixed(const float float_number) {
	std::cout << "Float constructor called" << std::endl;
	_fixed_point_number = std::roundf(float_number * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		std::cout << "Copy assignment operator called" << std::endl;
		_fixed_point_number = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
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

std::ostream& operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}
