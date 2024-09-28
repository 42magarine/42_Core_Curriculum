/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:14:41 by mott              #+#    #+#             */
/*   Updated: 2024/09/28 21:58:26 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& input_string) {
	char* end;

	if (input_string.length() == 1 && std::isprint(input_string[0]) && !std::isdigit(input_string[0])) {
		print(static_cast<char>(input_string[0]));
		return;
	}

	long int int_value = std::strtol(input_string.c_str(), &end, 10);
	if (*end == '\0') {
		if (int_value >= std::numeric_limits<int>::min() && int_value <= std::numeric_limits<int>::max()) {
			print(static_cast<int>(int_value));
			return;
		}
	}

	float float_value = std::strtof(input_string.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0') {
		print(static_cast<float>(float_value));
		return;
	}

	double double_value = std::strtod(input_string.c_str(), &end);
	if (*end == '\0') {
		print(static_cast<double>(double_value));
		return;
	}

	// if (input_string == "nanf" || input_string == "-inff" || input_string == "+inff") {
	// 	print(static_cast<float>(float_value));
	// 	return;
	// }

	// if (input_string == "nan" || input_string == "-inf" || input_string == "+inf") {
	// 	print(static_cast<double>(double_value));
	// 	return;
	// }

	std::cout << "Invalid input_string" << std::endl;
}

void ScalarConverter::print(char value) {
	std::cout << "char: " << value << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::print(int value) {
	if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() && isprint(static_cast<char>(value))) {
		std::cout << "char: " << static_cast<char>(value) << std::endl;
	}
	else {
		std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::print(float value) {
	if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() && isprint(static_cast<char>(value))) {
		std::cout << "char: " << static_cast<char>(value) << std::endl;
	}
	else {
		std::cout << "char: impossible" << std::endl;
	}

	if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
	else {
		std::cout << "int: impossible" << std::endl;
	}
	std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::print(double value) {
	if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max() && isprint(static_cast<char>(value))) {
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
	else {
		std::cout << "char: impossible" << std::endl;
	}

	if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
	else {
		std::cout << "int: impossible" << std::endl;
	}
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
}

ScalarConverter::ScalarConverter() {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}
