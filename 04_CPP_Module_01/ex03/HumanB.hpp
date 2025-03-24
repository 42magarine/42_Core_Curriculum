/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:00:15 by mott              #+#    #+#             */
/*   Updated: 2024/08/28 17:27:37 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <iostream>
#include <string>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class HumanB {
	public:
		HumanB(const std::string& name);

		void attack();
		void setWeapon(Weapon& weapon);

	private:
		std::string _name;
		Weapon* _weapon;
};

#endif // HUMANB_H
