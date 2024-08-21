/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:50:53 by mott              #+#    #+#             */
/*   Updated: 2024/08/21 14:09:40 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("default"), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "ClapTrap " << _name << " has been default-constructed." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "ClapTrap " << _name << " has been constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hit_points(other._hit_points), _energy_points(other._energy_points), _attack_damage(other._attack_damage) {
	std::cout << "ClapTrap " << _name << " has been copy-constructed." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " has been destroyed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		_name = other._name;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
	}
	std::cout << "ClapTrap " << _name << " has been copy-assigned." << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target) {
	if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " is out of hit points and cannot attack." << std::endl;
	}
	else if (_energy_points == 0) {
		std::cout << "ClapTrap " << _name << " has no energy left to attack." << std::endl;
	}
	else {
		_energy_points--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " is already down and cannot take more damage." << std::endl;
	}
	else {
		if (amount > _hit_points) {
			_hit_points = 0;
		}
		else {
			_hit_points -= amount;
		}
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage. Current hit points: " << _hit_points << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " cannot repair itself because it's out of hit points." << std::endl;
	}
	else if (_energy_points == 0) {
		std::cout << "ClapTrap " << _name << " has no energy left to repair itself." << std::endl;
	}
	else {
		_energy_points--;
		_hit_points += amount;

		std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount << " hit points. Current hit points: " << _hit_points << std::endl;
	}
}
