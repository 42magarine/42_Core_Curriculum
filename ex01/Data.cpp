/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:37:09 by mott              #+#    #+#             */
/*   Updated: 2024/09/29 12:53:15 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(): _id(42), _name("default") {
	std::cout << YELLOW << "(Data) Default constructor called" << RESET << std::endl;
}

Data::Data(int id, const std::string& name) : _id(id), _name(name) {
	std::cout << YELLOW << "(Data) Name constructor called" << RESET << std::endl;
}

Data::Data(const Data& other) : _id(other._id), _name(other._name) {
	std::cout << YELLOW << "(Data) Copy constructor called" << RESET << std::endl;
}

Data::~Data() {
	std::cout << YELLOW << "(Data) Destructor called" << RESET << std::endl;
}

Data& Data::operator=(const Data& other) {
	if (this != &other) {
		_id = other._id;
		_name = other._name;
		std::cout << YELLOW << "(Data) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

int Data::getId() const {
	return _id;
};

const std::string& Data::getName() const {
	return _name;
};
