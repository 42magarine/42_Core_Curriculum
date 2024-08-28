/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:53:11 by mott              #+#    #+#             */
/*   Updated: 2024/08/27 18:26:33 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "default constructor: " << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "constructor: " << YELLOW << _name << RESET << std::endl;
}

Zombie::~Zombie() {
	std::cout << "destructor: " << YELLOW << _name << RESET << std::endl;
}

void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
