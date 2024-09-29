/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:24:51 by mott              #+#    #+#             */
/*   Updated: 2024/09/29 12:57:55 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
};

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
};

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
