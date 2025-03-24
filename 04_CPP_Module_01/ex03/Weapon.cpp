/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:00:06 by mott              #+#    #+#             */
/*   Updated: 2024/08/28 17:16:38 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type) {
	std::cout << "constructor: " << YELLOW << _type << RESET << std::endl;
}

const std::string& Weapon::getType() {
	return _type;
}

void Weapon::setType(const std::string& type) {
	_type = type;
}
