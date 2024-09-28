/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:14:41 by mott              #+#    #+#             */
/*   Updated: 2024/09/28 15:16:32 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
