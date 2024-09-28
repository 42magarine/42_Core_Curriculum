/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:15:11 by mott              #+#    #+#             */
/*   Updated: 2024/09/28 21:59:00 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
	// if (argc != 2) {
	// 	std::cout << "You failed" << std::endl;
	// 	return 1;
	// }
	// ScalarConverter::convert(argv[1]);

	(void)argc;
	(void)argv;

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

	// ScalarConverter::convert("0");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("+inff");
	// ScalarConverter::convert("42.1f");

	return 0;
}
