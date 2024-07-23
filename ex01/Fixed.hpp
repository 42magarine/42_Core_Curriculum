/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:42:42 by mott              #+#    #+#             */
/*   Updated: 2024/07/23 20:47:44 by mott             ###   ########.fr       */
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
