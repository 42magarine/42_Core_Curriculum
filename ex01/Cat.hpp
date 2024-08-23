/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:31:50 by mott              #+#    #+#             */
/*   Updated: 2024/08/22 18:28:36 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include <iostream>
#include <string>

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &other);

		~Cat();

		Cat& operator=(const Cat &other);

		void makeSound() const override;
};

#endif // CAT_H
