/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:33:40 by mott              #+#    #+#             */
/*   Updated: 2024/09/01 18:26:40 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap st_default;
	ScavTrap st_name("scavvy");
	ScavTrap st_copy(st_name);
	ScavTrap st_assignment;
	st_assignment = st_default;
	std::cout << std::endl;

	st_name.attack("someone");
	st_name.takeDamage(7);
	st_name.beRepaired(5);
	st_name.guardGate();
	std::cout << std::endl;

	// tests virtual member function attack() in base class
	ClapTrap* pointer = &st_copy;
	pointer->attack("someone else");
	pointer->takeDamage(4);
	pointer->beRepaired(3);
	std::cout << std::endl;

	// tests virtual destructor in base class
	ClapTrap* pointer_to_heap = new ScavTrap("leaky");
	pointer_to_heap->attack("someone else");
	pointer_to_heap->takeDamage(4);
	pointer_to_heap->beRepaired(3);
	delete pointer_to_heap;
	std::cout << std::endl;

	// system("leaks scav");
	return 0;
}
