/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:44:51 by mott              #+#    #+#             */
/*   Updated: 2024/09/01 14:29:12 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"
#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Point {
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);

		~Point();

		Point& operator=(const Point& other) = delete; // Deleted to prevent assignment

		const Fixed& getX() const;
		const Fixed& getY() const;

	private:
		const Fixed _x;
		const Fixed _y;
};

std::ostream& operator<<(std::ostream& os, const Point& point);
bool bsp(const Point& a, const Point& b, const Point& c, const Point& point);

#endif // POINT_H
