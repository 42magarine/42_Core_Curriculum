/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:07:33 by mott              #+#    #+#             */
/*   Updated: 2024/08/21 18:07:34 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {
	std::cout << "Default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) {
	std::cout << "Copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
	}
	return *this;
}
