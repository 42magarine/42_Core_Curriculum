/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:15:11 by mott              #+#    #+#             */
/*   Updated: 2024/09/29 11:56:41 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "You failed" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);

	// (void)argc;
	// (void)argv;

	// ScalarConverter::convert("c");
	// ScalarConverter::convert("a");

	// ScalarConverter::convert("0");
	// ScalarConverter::convert("-42");
	// ScalarConverter::convert("42");

	// ScalarConverter::convert("0.0f");
	// ScalarConverter::convert("-4.2f");
	// ScalarConverter::convert("4.2f");

	// ScalarConverter::convert("0.0");
	// ScalarConverter::convert("-4.2");
	// ScalarConverter::convert("4.2");

	// ScalarConverter::convert("-inff");
	// ScalarConverter::convert("+inff");
	// ScalarConverter::convert("nanf");

	// ScalarConverter::convert("-inf");
	// ScalarConverter::convert("+inf");
	// ScalarConverter::convert("nan");

	// ScalarConverter::convert("2147483647");
	// ScalarConverter::convert("2147483648");
	// ScalarConverter::convert("-2147483648");
	// ScalarConverter::convert("-2147483649");

	// std::cout << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;
	// std::cout << std::numeric_limits<int>::max() << std::endl;
	// std::cout << std::fixed << std::setprecision(0) << std::numeric_limits<float>::max() << std::endl;
	// std::cout << std::fixed << std::setprecision(0) << std::numeric_limits<double>::max() << std::endl;

	// std::cout << static_cast<int>(std::numeric_limits<char>::min()) << std::endl;
	// std::cout << std::numeric_limits<int>::min() << std::endl;
	// std::cout << std::fixed << std::setprecision(0) << std::numeric_limits<float>::min() << std::endl;
	// std::cout << std::fixed << std::setprecision(0) << std::numeric_limits<double>::min() << std::endl;

	return 0;
}
