/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:14:04 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 15:14:05 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class AMateria {
	public:
		AMateria();
		AMateria(const AMateria& other);

		~AMateria();

		AMateria& operator=(const AMateria& other);

	private:
};

#endif // AMATERIA_H
