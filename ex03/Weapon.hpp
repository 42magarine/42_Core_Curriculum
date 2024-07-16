/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:00:03 by mott              #+#    #+#             */
/*   Updated: 2024/07/16 17:44:05 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
	private:
		std::string _type;

	public:
		Weapon(const std::string &type);
		const std::string &getType();
		void setType(const std::string &type);
};

#endif
