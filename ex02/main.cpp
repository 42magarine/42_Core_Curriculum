/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:05:52 by mott              #+#    #+#             */
/*   Updated: 2024/08/21 19:03:35 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	FragTrap ft_default;
	FragTrap ft_name("frag with a name");
	FragTrap ft_copy(ft_name);
	FragTrap ft_assignment;
	ft_assignment = ft_default;
	std::cout << std::endl;

	ft_name.attack("target1");
	ft_name.highFivesGuys();
	std::cout << std::endl;

	return 0;
}
