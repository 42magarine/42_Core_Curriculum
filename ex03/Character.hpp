/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:36:58 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 15:36:59 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Character {
	public:
		Character();
		Character(const Character& other);

		~Character();

		Character& operator=(const Character& other);

	private:
};

#endif // CHARACTER_H
