/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:00:18 by mott              #+#    #+#             */
/*   Updated: 2024/07/16 17:48:24 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(const std::string &name) : _name(name), _weapon(nullptr) {}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

void HumanB::attack() {
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
