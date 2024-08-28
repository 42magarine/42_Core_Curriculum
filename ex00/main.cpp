/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:53:17 by mott              #+#    #+#             */
/*   Updated: 2024/08/28 16:53:26 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	Zombie* heap_zombie = newZombie("heap_zombie");
	heap_zombie->announce();
	delete heap_zombie;

	randomChump("stack_zombie");

	system("leaks zombie");
	return 0;
}
