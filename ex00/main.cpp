/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:53:17 by mott              #+#    #+#             */
/*   Updated: 2024/07/15 17:27:42 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie *heapZombie = newZombie("heapZombie");
	heapZombie->announce();
	delete heapZombie;

	randomChump("stackZombie");

	// system("leaks BraiiiiiiinnnzzzZ");
	return 0;
}
