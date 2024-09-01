/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:07:55 by mott              #+#    #+#             */
/*   Updated: 2024/09/01 16:24:37 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);

		~DiamondTrap();

		DiamondTrap& operator=(const DiamondTrap& other);

		void whoAmI();

	private:
		std::string _name;
};

#endif // DIAMONDTRAP_H
