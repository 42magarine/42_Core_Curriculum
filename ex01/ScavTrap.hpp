/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:30:11 by mott              #+#    #+#             */
/*   Updated: 2024/08/21 14:37:53 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include <string>

class ScavTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);

		~ScavTrap();

		ScavTrap& operator=(const ScavTrap &other);

		void attack(const std::string &target);
		void guardGate();
};

#endif // SCAVTRAP_H
