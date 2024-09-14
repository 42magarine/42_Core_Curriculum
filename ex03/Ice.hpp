/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:21:32 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 15:47:18 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"
#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice& other);

		~Ice();

		Ice& operator=(const Ice& other);

	private:
};

#endif // ICE_H
