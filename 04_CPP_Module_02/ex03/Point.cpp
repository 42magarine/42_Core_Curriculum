/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:44:46 by mott              #+#    #+#             */
/*   Updated: 2024/09/01 14:28:45 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	std::cout << YELLOW << "(Point) Default constructor called" << RESET << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	std::cout << YELLOW << "(Point) Constructor called" << RESET << std::endl;
}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {
	std::cout << YELLOW << "(Point) Copy constructor called" << RESET << std::endl;
}

Point::~Point() {
	std::cout << YELLOW << "(Point) Destructor called" << RESET << std::endl;
}

const Fixed& Point::getX() const {
	return _x;
}

const Fixed& Point::getY() const {
	return _y;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << "(" << point.getX() << ", " << point.getY() << ")";
	return os;
}
