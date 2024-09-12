/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:43:46 by mott              #+#    #+#             */
/*   Updated: 2024/09/12 14:30:45 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);

		~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& other);

		void makeSound() const;
		std::string getType() const;

	protected:
		std::string _type;
};

#endif // WRONGANIMAL_H
