/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:31:56 by mott              #+#    #+#             */
/*   Updated: 2024/08/22 18:29:25 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &other);

		~Dog();

		Dog& operator=(const Dog &other);

		void makeSound() const override;
};

#endif // DOG_H
