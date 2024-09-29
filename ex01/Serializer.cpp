/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:24:51 by mott              #+#    #+#             */
/*   Updated: 2024/09/29 12:25:16 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer& other) {
	(void)other;
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

Serializer::~Serializer() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}
