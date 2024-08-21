/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:09:11 by mott              #+#    #+#             */
/*   Updated: 2024/08/21 20:40:17 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap dt_default;
	DiamondTrap dt_name("diamond with a name");
	std::cout << std::endl;

	dt_default.attack("target1");
	dt_default.guardGate();
	dt_default.highFivesGuys();
	dt_default.whoAmI();
	std::cout << std::endl;

	dt_name.attack("target2");
	dt_name.guardGate();
	dt_name.highFivesGuys();
	dt_name.whoAmI();
	std::cout << std::endl;

	return 0;
}
