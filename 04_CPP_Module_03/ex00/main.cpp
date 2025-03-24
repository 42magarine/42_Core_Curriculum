/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:51:03 by mott              #+#    #+#             */
/*   Updated: 2024/09/01 17:19:12 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap ct_default; 					// Default constructor
	ClapTrap ct_name("clappy");				// Name constructor
	ClapTrap ct_copy(ct_name);				// Copy constructor
	// ClapTrap ct_assignment = ct_default;	// Uses the Copy constructor
	ClapTrap ct_assignment;
	ct_assignment = ct_default;				// Copy assignment operator
	std::cout << std::endl;

	// standard attack, damage and repair
	ct_default.attack("someone");
	ct_default.takeDamage(8);
	ct_default.beRepaired(8);
	std::cout << std::endl;

	// attack, damage and repair without hit points
	ct_name.takeDamage(12);
	ct_name.attack("someone else");
	ct_name.takeDamage(12);
	ct_name.beRepaired(12);
	std::cout << std::endl;

	// attack, damage and repair without energy points
	for (int i = 0; i < 10; i++) {
		ct_copy.attack("someone else else");
	}
	ct_copy.attack("someone else else");
	ct_copy.takeDamage(4);
	ct_copy.beRepaired(4);
	std::cout << std::endl;

	return 0;
}
