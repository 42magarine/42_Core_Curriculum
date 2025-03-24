/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:45:21 by mott              #+#    #+#             */
/*   Updated: 2024/08/28 16:54:30 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie* zombie_horde = zombieHorde(8, "zombie_horde");

	for (int i = 0; i < 8; i++) {
		zombie_horde[i].announce();
	}

	delete[] zombie_horde;

	system("leaks zombie");
	return 0;
}
