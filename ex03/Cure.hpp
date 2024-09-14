/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:21:27 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 17:28:18 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Cure : public AMateria {
	public:
		Cure();
		// Cure(const std::string& type);
		Cure(const Cure& other);

		~Cure();

		Cure& operator=(const Cure& other);

		AMateria* clone() const;
		void use(ICharacter& target);

	private:
};

#endif // CURE_H
