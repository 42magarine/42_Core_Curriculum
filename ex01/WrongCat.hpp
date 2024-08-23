/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:45:49 by mott              #+#    #+#             */
/*   Updated: 2024/08/23 13:51:47 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat &other);

		~WrongCat();

		WrongCat& operator=(const WrongCat &other);

		void makeSound() const;
};

#endif // WRONGCAT_H
