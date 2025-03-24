/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:42:42 by mott              #+#    #+#             */
/*   Updated: 2024/08/31 14:11:12 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Fixed {
	public:
		Fixed();
		Fixed(const int int_number);
		Fixed(const float float_number);
		Fixed(const Fixed& other);

		~Fixed();

		Fixed& operator=(const Fixed& other);

		int getRawBits() const;
		void setRawBits(const int raw);
		float toFloat() const;
		int toInt() const;

	private:
		int _fixed_point_number;
		static const int _fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif // FIXED_H
