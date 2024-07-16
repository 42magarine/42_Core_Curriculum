/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:00:09 by mott              #+#    #+#             */
/*   Updated: 2024/07/16 17:46:37 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include <string>
#include "Weapon.hpp"

class HumanA {
	private:
		std::string _name;
		Weapon &_weapon;

	public:
		HumanA(const std::string &name, Weapon &weapon);
		void attack();
};

#endif
