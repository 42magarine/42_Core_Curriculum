/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:45:21 by mott              #+#    #+#             */
/*   Updated: 2024/07/16 13:24:32 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie *zombiePointer = zombieHorde(8, "zombieHorde");

	for (int i = 0; i < 8; ++i) {
		zombiePointer[i].announce();
	}

	delete[] zombiePointer;
	// system("leaks Moar_brainz!");
	return 0;
}
