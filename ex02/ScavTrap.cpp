/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:30:16 by mott              #+#    #+#             */
/*   Updated: 2024/09/01 18:50:53 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << YELLOW << "(ScavTrap) Default constructor called with: " << _name << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << YELLOW << "(ScavTrap) Name constructor called with: " << _name << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << YELLOW << "(ScavTrap) Copy constructor called with: " << _name << RESET << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << YELLOW << "(ScavTrap) Destructor called with: " << _name << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		std::cout << YELLOW << "(ScavTrap) Copy assignment operator called with: " << _name << RESET << std::endl;
		ClapTrap::operator=(other);
	}
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (_hit_points == 0) {
		std::cout << "ScavTrap " << _name << " can't attack, because it has no hit points left." << std::endl;
	}
	else if (_energy_points == 0) {
		std::cout << "ScavTrap " << _name << " can't attack, because it has no energy points left." << std::endl;
	}
	else {
		_energy_points--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage." << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode." << std::endl;
}
