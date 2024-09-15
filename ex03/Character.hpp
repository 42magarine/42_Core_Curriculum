/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:36:58 by mott              #+#    #+#             */
/*   Updated: 2024/09/15 15:11:47 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Character : public ICharacter {
	public:
		Character();
		Character(const std::string& name);
		Character(const Character& other);

		~Character();

		Character& operator=(const Character& other);

		const std::string& getName() const override;
		void equip(AMateria* m) override;
		void unequip(int idx) override;
		void use(int idx, ICharacter& target) override;

	private:
		std::string _name;
		AMateria* _inventory[4];
};

#endif // CHARACTER_H
