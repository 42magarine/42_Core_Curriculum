/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:31:50 by mott              #+#    #+#             */
/*   Updated: 2024/09/12 14:07:40 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
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
};

#endif // CAT_H
