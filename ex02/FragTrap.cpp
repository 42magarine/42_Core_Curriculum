/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:07:33 by mott              #+#    #+#             */
/*   Updated: 2024/08/21 18:57:23 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap " << _name << " has been default-constructed." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap " << _name << " has been constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap " << _name << " has been copy-constructed." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " has been destroyed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << _name << " has been copy-assigned." << std::endl;
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " is requesting a high five!" << std::endl;
}
