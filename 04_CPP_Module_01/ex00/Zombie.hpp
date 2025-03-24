/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:53:14 by mott              #+#    #+#             */
/*   Updated: 2024/08/27 18:40:11 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Zombie {
	public:
		Zombie();
		Zombie(std::string name);

		~Zombie();

		void announce();

	private:
		std::string	_name;
};

Zombie*	newZombie(std::string name);
void randomChump(std::string name);

#endif // ZOMBIE_H
