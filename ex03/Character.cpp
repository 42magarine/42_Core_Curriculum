/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:36:55 by mott              #+#    #+#             */
/*   Updated: 2024/09/17 18:41:30 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// The inventory is empty at construction.
Character::Character() : _name("default") {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = nullptr;
	}
	std::cout << YELLOW << "(Character) Default constructor called with " << _name << RESET << std::endl;
}

// Your Character must have a constructor taking its name as a parameter.
Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = nullptr;
	}
	std::cout << YELLOW << "(Character) Name constructor called with " << _name << RESET << std::endl;
}

Character::Character(const Character& other) : _name(other._name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = nullptr;
	}
	copy_inventory(other);
	std::cout << YELLOW << "(Character) Copy constructor called with " << _name << RESET << std::endl;
}

// Of course, the Materias must be deleted when a Character is destroyed.
Character::~Character() {
	delete_inventory();
	std::cout << YELLOW << "(Character) Destructor called with " << _name << RESET << std::endl;
}

// During copy, the Materias of a Character must be deleted before the new ones are added to their inventory.
Character& Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other._name;
		delete_inventory();
		copy_inventory(other);
		std::cout << YELLOW << "(Character) Copy assignment operator called with " << _name << RESET << std::endl;
	}
	return *this;
}

const std::string& Character::getName() const {
	return _name;
};

// In case they try to add a Materia to a full inventory, or use/unequip an unexisting Materia, don’t do anything.

// They equip the Materias in the first empty slot they find. This means, in this order: from slot 0 to slot 3.
void Character::equip(AMateria* m) {
	if (m == nullptr) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == nullptr) {
			_inventory[i] = m->clone();
			return;
		}
	}
};

// The unequip() member function must NOT delete the Materia!
void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && _inventory[idx] != nullptr) {
		_inventory[idx] = nullptr;
	}
};

// The use(int, ICharacter&) member function will have to use the Materia at the slot[idx], and pass the target parameter to the AMateria::use function.
void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx] != nullptr) {
		_inventory[idx]->use(target);
	}
};

void Character::delete_inventory() {
	for (int i = 0; i < 4; i++) {
		delete _inventory[i];
		_inventory[i] = nullptr;
	}
}

// Any copy (using copy constructor or copy assignment operator) of a Character must be deep.
void Character::copy_inventory(const Character& other) {
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i] != nullptr) {
			_inventory[i] = other._inventory[i]->clone();
		}
	}
}

AMateria* Character::getInventory(int idx) const {
	return _inventory[idx];
};
