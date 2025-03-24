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

#include "Fixed.hpp"

int main() {
	{
		Fixed a;
		const Fixed b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max(a, b) << std::endl;
	}
	// {
	// 	Fixed a(1.0f);
	// 	std::cout << a.getRawBits() << std::endl;

	// 	Fixed b(1);
	// 	std::cout << b.getRawBits() << std::endl;

	// 	Fixed c(a * b);
	// 	std::cout << c.getRawBits() << std::endl;
	// 	std::cout << c << std::endl;
	// }
	// {
	// 	Fixed a(8);
	// 	Fixed b(0);

	// 	Fixed c = a + b;
	// 	std::cout << "a is " << a << std::endl;
	// 	std::cout << "b is " << b << std::endl;
	// 	std::cout << "a + b is " << c << std::endl;

	// 	c = a - b;
	// 	std::cout << "a is " << a << std::endl;
	// 	std::cout << "b is " << b << std::endl;
	// 	std::cout << "a - b is " << c << std::endl;

	// 	c = a * b;
	// 	std::cout << "a is " << a << std::endl;
	// 	std::cout << "b is " << b << std::endl;
	// 	std::cout << "a * b is " << c << std::endl;

	// 	c = a / b;
	// 	std::cout << "a is " << a << std::endl;
	// 	std::cout << "b is " << b << std::endl;
	// 	std::cout << "a / b is " << c << std::endl;
	// }
	// {
	// 	Fixed a(8);
	// 	Fixed b(8.0f);

	// 	std::cout << "a is " << a << std::endl;
	// 	std::cout << "b is " << b << std::endl;

	// 	std::cout << "a > b is " << (a > b) << std::endl;
	// 	std::cout << "a < b is " << (a < b) << std::endl;
	// 	std::cout << "a >= b is " << (a >= b) << std::endl;
	// 	std::cout << "a <= b is " << (a <= b) << std::endl;
	// 	std::cout << "a == b is " << (a == b) << std::endl;
	// 	std::cout << "a != b is " << (a != b) << std::endl;
	// }
	// {
	// 	Fixed a(42.42f);
	// 	Fixed b(a++);

	// 	std::cout << "a is " << a << std::endl;
	// 	std::cout << "b is " << b << std::endl;

	// 	std::cout << "min(a, b) is " << Fixed::min(a, b) << std::endl;
	// 	std::cout << "max(a, b) is " << Fixed::max(a, b) << std::endl;
	// }

	return 0;
}
