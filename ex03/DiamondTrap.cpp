/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:07:52 by mott              #+#    #+#             */
/*   Updated: 2024/08/21 19:07:53 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() {
	std::cout << "Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
	std::cout << "Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
	}
	return *this;
}
