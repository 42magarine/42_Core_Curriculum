/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:45:12 by mott              #+#    #+#             */
/*   Updated: 2024/08/27 18:29:38 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name) {
	Zombie* zombie_horde = new Zombie[n];

	for (int i = 0; i < n; i++) {
		zombie_horde[i].setName(name);
	}
	return zombie_horde;
}
