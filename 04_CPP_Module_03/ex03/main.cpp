/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:09:11 by mott              #+#    #+#             */
/*   Updated: 2024/09/11 19:02:58 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap dt_default;
	DiamondTrap dt_name("diamonddy");
	DiamondTrap dt_copy(dt_name);
	DiamondTrap dt_assignment;
	dt_assignment = dt_default;
	std::cout << std::endl;

	dt_name.attack("someone");
	dt_name.takeDamage(7);
	dt_name.beRepaired(5);
	dt_name.guardGate();
	dt_name.highFivesGuys();
	dt_name.whoAmI();
	std::cout << std::endl;

	dt_assignment.attack("someone");
	dt_assignment.takeDamage(7);
	dt_assignment.beRepaired(5);
	dt_assignment.guardGate();
	dt_assignment.highFivesGuys();
	dt_assignment.whoAmI();
	std::cout << std::endl;

	return 0;
}
