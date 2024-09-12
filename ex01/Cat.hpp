/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:31:50 by mott              #+#    #+#             */
/*   Updated: 2024/09/12 18:58:50 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& other);

		~Cat();

		Cat& operator=(const Cat& other);

		void makeSound() const override;
		Brain* getBrain() const;

	private:
		Brain* _pointer;
};

#endif // CAT_H
