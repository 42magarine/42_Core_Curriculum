/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:33:40 by mott              #+#    #+#             */
/*   Updated: 2024/08/21 18:00:26 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap st_default;
	ScavTrap st_name("scav with a name");
	ScavTrap st_copy(st_name);
	ScavTrap st_assignment;
	st_assignment = st_default;
	std::cout << std::endl;

	st_name.attack("target1");
	st_name.guardGate();
	std::cout << std::endl;

	ClapTrap *pointer = &st_name;
	pointer->attack("target2");
	std::cout << std::endl;

	return 0;
}
