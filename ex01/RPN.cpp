/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:07 by mott              #+#    #+#             */
/*   Updated: 2024/10/20 15:29:08 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

RPN::RPN(const RPN& other) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

RPN::~RPN() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}
