/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:42:42 by mott              #+#    #+#             */
/*   Updated: 2024/08/09 13:55:00 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	public:
		// Constructor
		Fixed();
		Fixed(const int int_number);
		Fixed(const float float_number);
		Fixed(const Fixed &other);

		// Destructor
		~Fixed();

		// Copy assignment operator overload
		Fixed& operator=(const Fixed &other);

		// Member functions
		int getRawBits() const;
		void setRawBits(const int raw);
		float toFloat() const;
		int toInt() const;

		// Comparison operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// Arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// Increment and decrement operators
		Fixed& operator++();	// Pre-increment
		Fixed operator++(int);	// Post-increment
		Fixed& operator--();	// Pre-increment
		Fixed operator--(int);	// Post-increment

		// Static member functions
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);

	private:
		int _fixed_point_number;
		static const int _fractional_bits = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif // FIXED_H
