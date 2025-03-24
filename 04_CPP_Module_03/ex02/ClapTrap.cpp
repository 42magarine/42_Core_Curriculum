/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:29:37 by mott              #+#    #+#             */
/*   Updated: 2024/09/11 18:11:11 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << YELLOW << "(ClapTrap) Default constructor called with: " << _name << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << YELLOW << "(ClapTrap) Name constructor called with: " << _name << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hit_points(other._hit_points), _energy_points(other._energy_points), _attack_damage(other._attack_damage) {
	std::cout << YELLOW << "(ClapTrap) Copy constructor called with: " << _name << RESET << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << YELLOW << "(ClapTrap) Destructor called with: " << _name << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		_name = other._name;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
		std::cout << YELLOW << "(ClapTrap) Copy assignment operator called with: " << _name << RESET << std::endl;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " can't attack, because it has no hit points left." << std::endl;
	}
	else if (_energy_points == 0) {
		std::cout << "ClapTrap " << _name << " can't attack, because it has no energy points left." << std::endl;
	}
	else {
		_energy_points--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " is already down and can't take more damage." << std::endl;
	}
	else if (amount >= _hit_points) {
		_hit_points = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage. Current hit points: " << _hit_points << std::endl;
	}
	else {
		_hit_points -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage. Current hit points: " << _hit_points << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " can't repair itself, because it has no hit points left." << std::endl;
	}
	else if (_energy_points == 0) {
		std::cout << "ClapTrap " << _name << " can't repair itself, because it has no energy points left." << std::endl;
	}
	else {
		_energy_points--;
		_hit_points += amount;
		std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount << " hit points. Current hit points: " << _hit_points << std::endl;
	}
}
