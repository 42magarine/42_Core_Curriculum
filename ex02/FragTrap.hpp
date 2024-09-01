/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:07:36 by mott              #+#    #+#             */
/*   Updated: 2024/09/01 16:23:44 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);

		~FragTrap();

		FragTrap& operator=(const FragTrap& other);

		void highFivesGuys();
};

#endif // FRAGTRAP_H
