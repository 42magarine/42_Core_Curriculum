/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:44:51 by mott              #+#    #+#             */
/*   Updated: 2024/08/31 15:44:52 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
	public:
		Point();
		Point(const Point &other);

		~Point();

		Point& operator=(const Point &other);

	private:
};

#endif // POINT_H
