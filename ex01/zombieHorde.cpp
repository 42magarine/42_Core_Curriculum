/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:45:12 by mott              #+#    #+#             */
/*   Updated: 2024/07/16 13:04:09 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	Zombie *zombiePointer = new Zombie[N];
	
	for (int i = 0; i < N; ++i) {
		zombiePointer[i].setName(name);
	}
	return zombiePointer;
}
