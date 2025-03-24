/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:05:52 by mott              #+#    #+#             */
/*   Updated: 2024/09/11 17:19:28 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	FragTrap ft_default;
	FragTrap ft_name("fraggy");
	FragTrap ft_copy(ft_name);
	FragTrap ft_assignment;
	ft_assignment = ft_default;
	std::cout << std::endl;

	ft_name.attack("someone");
	ft_name.takeDamage(7);
	ft_name.beRepaired(5);
	ft_name.highFivesGuys();
	std::cout << std::endl;

	return 0;
}
