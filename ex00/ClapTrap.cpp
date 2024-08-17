/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:50:53 by mott              #+#    #+#             */
/*   Updated: 2024/08/16 14:12:15 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		std::cout << "Copy assignment operator called" << std::endl;
		_name = other._name;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " can't attack, "
		          << _hit_points << " hit points left." << std::endl;
	}
	else if (_energy_points == 0) {
		std::cout << "ClapTrap " << _name << " can't attack, "
		          << _energy_points << " energy points left." << std::endl;
	}
	else {
		_energy_points--;
		std::cout << "ClapTrap " << _name << " attacks " << target
		          << ", causing" << _attack_damage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " can't take more damage, "
		          << _hit_points << " hit points left." << std::endl;
		return ;
	}
	if (_hit_points < amount) {
		_hit_points = 0;
	}
	else {
		_hit_points -= amount;
	}
	std::cout << "ClapTrap " << _name << " takes "
	          << amount << " damage, " << _hit_points << " hit points left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hit_points == 0) {
		std::cout << "ClapTrap " << _name << " can't repair itself, "
		          << _hit_points << " hit points left." << std::endl;
	}
	else if (_energy_points == 0) {
		std::cout << "ClapTrap " << _name << " can't repair itself, "
		          << _energy_points << " energy points left." << std::endl;
	}
	else {
		_energy_points--;
		_hit_points += amount;
		std::cout << "ClapTrap " << _name << " repairs itself by "
		          << amount << " hit points, " << _hit_points << "hit points left." << std::endl;
	}
}
