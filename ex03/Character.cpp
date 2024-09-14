/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:36:55 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 17:51:32 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	std::cout << YELLOW << "(Character) Default constructor called" << RESET << std::endl;
}

Character::Character(const std::string& name) : _name(name) {
	std::cout << YELLOW << "(Character) Name constructor called" << RESET << std::endl;
}

Character::Character(const Character& other) {
	std::cout << YELLOW << "(Character) Copy constructor called" << RESET << std::endl;
}

Character::~Character() {
	std::cout << YELLOW << "(Character) Destructor called" << RESET << std::endl;
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other._name;
		std::cout << YELLOW << "(Character) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

const std::string& Character::getName() const {
	return _name;
};

void Character::equip(AMateria* m) {

};

void Character::unequip(int idx) {

};

void Character::use(int idx, ICharacter& target) {

};
