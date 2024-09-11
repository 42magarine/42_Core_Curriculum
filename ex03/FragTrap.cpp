/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:07:33 by mott              #+#    #+#             */
/*   Updated: 2024/09/11 17:11:27 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << YELLOW << "(FragTrap) Default constructor called with: " << _name << RESET << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << YELLOW << "(FragTrap) Name constructor called with: " << _name << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << YELLOW << "(FragTrap) Copy constructor called with: " << _name << RESET << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << YELLOW << "(FragTrap) Destructor called with: " << _name << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		std::cout << YELLOW << "(FragTrap) Copy assignment operator called with: " << _name << RESET << std::endl;
		ClapTrap::operator=(other);
	}
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << " is requesting a high five!" << std::endl;
}
