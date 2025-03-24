/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:14:04 by mott              #+#    #+#             */
/*   Updated: 2024/09/16 14:21:15 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include <string>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class ICharacter;

class AMateria {
	public:
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& other);

		virtual ~AMateria();

		AMateria& operator=(const AMateria& other);

		const std::string& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;

	protected:
		std::string _type;
};

#endif // AMATERIA_H
