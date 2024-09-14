/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:21:29 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 15:21:30 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Ice::Ice(const Ice& other) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

Ice::~Ice() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}
