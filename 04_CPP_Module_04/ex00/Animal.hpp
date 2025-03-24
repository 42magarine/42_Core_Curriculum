/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:31:37 by mott              #+#    #+#             */
/*   Updated: 2024/09/12 14:43:33 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Animal {
	public:
		Animal();
		Animal(const Animal& other);

		virtual ~Animal();

		Animal& operator=(const Animal& other);

		virtual void makeSound() const;
		std::string getType() const;

	protected:
		std::string _type;
};

#endif // ANIMAL_H
