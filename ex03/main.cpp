/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:37:01 by mott              #+#    #+#             */
/*   Updated: 2024/09/01 15:22:43 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(2.5f, 5.0f);
	bool result;

	Point inside(2.5f, 1.0f);
	result = bsp(a, b, c, inside);
	std::cout << "The point " << inside << " is inside the triangle: " << (result ? "True" : "False") << std::endl;

	Point outside(5.0f, 5.0f);
	result = bsp(a, b, c, outside);
	std::cout << "The point " << outside << " is inside the triangle: " << (result ? "True" : "False") << std::endl;

	Point edge(2.5f, 0.0f);
	result = bsp(a, b, c, edge);
	std::cout << "The point " << edge << " is inside the triangle: " << (result ? "True" : "False") << std::endl;

	Point vertex(0.0f, 0.0f);
	result = bsp(a, b, c, vertex);
	std::cout << "The point " << vertex << " is inside the triangle: " << (result ? "True" : "False") << std::endl;

	return 0;
}
