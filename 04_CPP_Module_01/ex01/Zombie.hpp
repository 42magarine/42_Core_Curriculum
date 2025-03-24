/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:45:18 by mott              #+#    #+#             */
/*   Updated: 2024/08/27 18:40:23 by mott             ###   ########.fr       */
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
		void setName(std::string name);

	private:
		std::string	_name;
};

Zombie* zombieHorde(int n, std::string name);

#endif // ZOMBIE_H
