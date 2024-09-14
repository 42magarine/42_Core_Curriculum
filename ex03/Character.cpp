/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:36:55 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 15:36:56 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Character::Character(const Character& other) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

Character::~Character() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}
