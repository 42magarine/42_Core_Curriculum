/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:07:52 by mott              #+#    #+#             */
/*   Updated: 2024/08/21 20:58:12 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap(), ScavTrap(), FragTrap(), _name("default") {
	ClapTrap::_name += "_clap_name";
	_hit_points = FragTrap::_hit_points;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap " << _name << " has been default-constructed." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name") , ScavTrap(name), FragTrap(name), _name(name) {
	_hit_points = FragTrap::_hit_points;
	_energy_points = ScavTrap::_energy_points;
	_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap " << _name << " has been constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other) {
	std::cout << "DiamondTrap " << _name << " has been copy-constructed." << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " has been destroyed." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "DiamondTrap " << _name << " has been copy-assigned." << std::endl;
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
