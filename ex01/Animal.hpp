/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:31:37 by mott              #+#    #+#             */
/*   Updated: 2024/08/22 18:11:40 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {
	public:
		Animal();
		Animal(const Animal &other);

		virtual ~Animal();

		Animal& operator=(const Animal &other);

		virtual void makeSound() const;
		std::string getType() const;

	protected:
		std::string _type;
};

#endif // ANIMAL_H
