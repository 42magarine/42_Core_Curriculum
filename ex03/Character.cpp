/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:36:55 by mott              #+#    #+#             */
/*   Updated: 2024/09/15 17:35:15 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default") {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = nullptr;
	}
	std::cout << YELLOW << "(Character) Default constructor called with " << _name << RESET << std::endl;
}

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = nullptr;
	}
	std::cout << YELLOW << "(Character) Name constructor called with " << _name << RESET << std::endl;
}

Character::Character(const Character& other) : _name(other._name) {
	// _inventory[] delete + new
	std::cout << YELLOW << "(Character) Copy constructor called with " << _name << RESET << std::endl;
}

Character::~Character() {
	// _inventory delete
	std::cout << YELLOW << "(Character) Destructor called with " << _name << RESET << std::endl;
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other._name;
		// _inventory[] delete + new
		std::cout << YELLOW << "(Character) Copy assignment operator called with " << _name << RESET << std::endl;
	}
	return *this;
}

const std::string& Character::getName() const {
	return _name;
};

void Character::equip(AMateria* m) {
	if (m == nullptr) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == nullptr) {
			_inventory[i] = m;
			return;
		}
	}
};

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4) {
		// save pointer
		_inventory[idx] = nullptr;
	}
};

void Character::use(int idx, ICharacter& target) {
	if (_inventory[idx] != nullptr && idx >= 0 && idx < 4) {
		_inventory[idx]->use(target);
	}
};
