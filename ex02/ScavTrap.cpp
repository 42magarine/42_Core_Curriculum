/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:30:16 by mott              #+#    #+#             */
/*   Updated: 2024/08/21 17:16:25 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap " << _name << " has been default-constructed." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap " << _name << " has been constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap " << _name << " has been copy-constructed." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " has been destroyed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		// _name = other._name;
		// _hit_points = other._hit_points;
		// _energy_points = other._energy_points;
		// _attack_damage = other._attack_damage;
	}
	std::cout << "ScavTrap " << _name << " has been copy-assigned." << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (_hit_points == 0) {
		std::cout << "ScavTrap " << _name << " is out of hit points and cannot attack." << std::endl;
	}
	else if (_energy_points == 0) {
		std::cout << "ScavTrap " << _name << " has no energy left to attack." << std::endl;
	}
	else {
		_energy_points--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage." << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode." << std::endl;
}
