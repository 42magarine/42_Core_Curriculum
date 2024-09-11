/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:07:52 by mott              #+#    #+#             */
/*   Updated: 2024/09/11 18:50:54 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _name("default") {
	ClapTrap::_name += "_clap_name";
	_hit_points = FragTrap::_hit_points;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;
	std::cout << YELLOW << "(DiamondTrap) Default constructor called with: " << _name << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name") , ScavTrap(name), FragTrap(name), _name(name) {
	_hit_points = FragTrap::_hit_points;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;
	std::cout << YELLOW << "(DiamondTrap) Name constructor called with: " << _name << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
	std::cout << YELLOW << "(DiamondTrap) Copy constructor called with: " << _name << RESET << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << YELLOW << "(DiamondTrap) Destructor called with: " << _name << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		// ScavTrap::operator=(other);
		// FragTrap::operator=(other);
		_name = other._name;
		std::cout << YELLOW << "(DiamondTrap) Copy assignment operator called with: " << _name << RESET << std::endl;
	}
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap " << _name << " is also a ClapTrap " << ClapTrap::_name << std::endl;
}
