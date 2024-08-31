/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:44:46 by mott              #+#    #+#             */
/*   Updated: 2024/08/31 15:44:47 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() {
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Point &other) {
	std::cout << "Copy constructor called" << std::endl;
}

Point::~Point() {
	std::cout << "Destructor called" << std::endl;
}

Point& Point::operator=(const Point &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
	}
	return *this;
}
