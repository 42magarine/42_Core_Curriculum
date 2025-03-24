/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:02:06 by mott              #+#    #+#             */
/*   Updated: 2024/09/12 19:09:39 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << YELLOW << "(Brain) Default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other._ideas[i];
	}
	std::cout << YELLOW << "(Brain) Copy constructor called" << RESET << std::endl;
}

Brain::~Brain() {
	std::cout << YELLOW << "(Brain) Destructor called" << RESET << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = other._ideas[i];
		}
		std::cout << YELLOW << "(Brain) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

std::string Brain::getIdeas(unsigned int i) const {
	return _ideas[i];
}

void Brain::setIdeas(unsigned int i, std::string idea) {
	_ideas[i] = idea;
}
