/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:02:06 by mott              #+#    #+#             */
/*   Updated: 2024/08/23 14:48:06 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other._ideas[i];
	}
	std::cout << "Copy constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}
