/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:21:09 by mott              #+#    #+#             */
/*   Updated: 2024/08/08 16:22:14by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void) {

	// Fixed a;
	// const Fixed b(Fixed(5.05f) * Fixed(2));

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// std::cout << b << std::endl;

	// std::cout << Fixed::max(a, b) << std::endl;

	Fixed a(1.0f);
	std::cout << a.getRawBits() << std::endl;

	Fixed b(1.0f);
	std::cout << b.getRawBits() << std::endl;

	Fixed c(a * b);
	std::cout << c.getRawBits() << std::endl;
	std::cout << c << std::endl;

	return 0;
}
