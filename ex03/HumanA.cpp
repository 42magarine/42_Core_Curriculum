/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:00:12 by mott              #+#    #+#             */
/*   Updated: 2024/07/16 17:47:30 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name) , _weapon(weapon){}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
