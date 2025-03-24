/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:42:42 by mott              #+#    #+#             */
/*   Updated: 2024/08/31 13:45:50 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed& other);

		~Fixed();

		Fixed& operator=(const Fixed& other);

		int getRawBits() const;
		void setRawBits(const int raw);

	private:
		int _fixed_point_number;
		static const int _fractional_bits = 8;
};

#endif // FIXED_H
