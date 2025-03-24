/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:44:26 by mott              #+#    #+#             */
/*   Updated: 2024/08/31 14:28:39 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	// std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	// std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	// std::cout << "d is " << d.toFloat() << " as float" << std::endl;

	// Fixed e(8.1f);
	// std::cout << "e is " << e << std::endl;
	// std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	// std::cout << "e is " << e.toFloat() << " as float" << std::endl;

	return 0;
}
