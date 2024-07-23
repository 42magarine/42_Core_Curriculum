/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:26:46 by mott              #+#    #+#             */
/*   Updated: 2024/07/23 15:26:47 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

class Fixed {
	public:
		// Default constructor
		Fixed();

		// Copy constructor
		Fixed(const Fixed &other);

		// Copy assignment operator
		Fixed& operator=(const Fixed &other);

		// Destructor
		~Fixed();

	private:
		// Class members
};

#endif // FIXED_H
