/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:37:01 by mott              #+#    #+#             */
/*   Updated: 2024/08/31 20:02:54 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
	Point a;
	Point b;
	Point c;
	bool result;

	Point inside;
	result = bsp(a, b, c, inside);
	std::cout << "The point " << inside << " is inside the triangle: " << (result ? "True" : "False") << std::endl;

	Point outside;
	result = bsp(a, b, c, outside);
	std::cout << "The point " << outside << " is inside the triangle: " << (result ? "True" : "False") << std::endl;

	return 0;
}
