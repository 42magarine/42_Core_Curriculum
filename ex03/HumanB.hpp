/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:00:15 by mott              #+#    #+#             */
/*   Updated: 2024/07/16 17:47:45 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon *_weapon;

	public:
		HumanB(const std::string &name);
		void setWeapon(Weapon &weapon);
		void attack();
};

#endif
