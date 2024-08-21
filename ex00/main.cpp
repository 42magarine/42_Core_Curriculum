/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:51:03 by mott              #+#    #+#             */
/*   Updated: 2024/08/21 14:07:36 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	// default constructor, named constructor, copy construtor and assignment operator
	ClapTrap ct_default;
	ClapTrap ct_name("clap with a name");
	ClapTrap ct_copy(ct_name);
	ClapTrap ct_assignment;
	ct_assignment = ct_default;
	std::cout << std::endl;

	// standard attack, damage and repair
	ct_default.attack("target1");
	ct_default.takeDamage(8);
	ct_default.beRepaired(8);
	std::cout << std::endl;

	// attack, damage and repair without hit points
	ct_name.takeDamage(12);
	ct_name.attack("target2");
	ct_name.takeDamage(12);
	ct_name.beRepaired(12);
	std::cout << std::endl;

	// attack, damage and repair without energy points
	for (int i = 0; i < 10; i++) {
		ct_copy.attack("target3");
	}
	ct_copy.attack("target2");
	ct_copy.takeDamage(4);
	ct_copy.beRepaired(4);
	std::cout << std::endl;

	return 0;
}
