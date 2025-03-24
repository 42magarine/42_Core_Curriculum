/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:42:45 by mott              #+#    #+#             */
/*   Updated: 2024/09/30 13:39:17 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point_number(0) {
	std::cout << YELLOW << "(Fixed) Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int int_number) {
	std::cout << YELLOW << "(Fixed) Int constructor called" << RESET << std::endl;
	_fixed_point_number = int_number << _fractional_bits;
}

Fixed::Fixed(const float float_number) {
	std::cout << YELLOW << "(Fixed) Float constructor called" << RESET << std::endl;
	_fixed_point_number = std::roundf(float_number * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed& other) : _fixed_point_number(other.getRawBits()) {
	std::cout << YELLOW << "(Fixed) Copy constructor called" << RESET << std::endl;
}

Fixed::~Fixed() {
	std::cout << YELLOW << "(Fixed) Destructor called" << RESET << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		std::cout << YELLOW << "(Fixed) Copy assignment operator called" << RESET << std::endl;
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

bool Fixed::operator>(const Fixed& other) const {
	return _fixed_point_number > other._fixed_point_number;
}

bool Fixed::operator<(const Fixed& other) const {
	return _fixed_point_number < other._fixed_point_number;
}

bool Fixed::operator>=(const Fixed& other) const {
	return _fixed_point_number >= other._fixed_point_number;
}
;
bool Fixed::operator<=(const Fixed& other) const {
	return _fixed_point_number <= other._fixed_point_number;
}

bool Fixed::operator==(const Fixed& other) const {
	return _fixed_point_number == other._fixed_point_number;
}

bool Fixed::operator!=(const Fixed& other) const {
	return _fixed_point_number != other._fixed_point_number;
}

Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {	// Pre-increment ++obj
	_fixed_point_number++;
	return *this;
}

Fixed Fixed::operator++(int) {	// Post-increment obj++
	Fixed temp = *this;
	_fixed_point_number++;
	return temp;
}

Fixed& Fixed::operator--() {	// Pre-decrement --obj
	_fixed_point_number--;
	return *this;
}

Fixed Fixed::operator--(int) {	// Post-decrement obj--
	Fixed temp = *this;
	_fixed_point_number--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
