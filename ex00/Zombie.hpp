/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:53:14 by mott              #+#    #+#             */
/*   Updated: 2024/07/15 17:25:18 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie();
		void announce();

	private:
		Zombie();
		std::string	name;
};

Zombie*	newZombie(std::string name);
void randomChump(std::string name);

#endif
