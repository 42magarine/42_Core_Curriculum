/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:42:42 by mott              #+#    #+#             */
/*   Updated: 2024/08/09 13:17:29 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const int int_number);
		Fixed(const float float_number);

		Fixed(const Fixed &other);

		Fixed& operator=(const Fixed &other);

		~Fixed();

		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		int getRawBits() const;
		void setRawBits(const int raw);
		float toFloat() const;
		int toInt() const;

	private:
		int _fixed_point_number;
		static const int _fractional_bits = 8;
};

std::ostream& operator<<(std::ostream &os, const Fixed &fixed);

#endif // FIXED_H
