/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:49:46 by mott              #+#    #+#             */
/*   Updated: 2024/09/30 14:49:47 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Span::Span(const Span& other) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

Span::~Span() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}
