/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:52:48 by mott              #+#    #+#             */
/*   Updated: 2024/09/29 21:29:43 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
	// Array int_array;
	Array int_array(10);
	Array int_array_two(int_array);
	Array int_array_three(int_array);

	for (unsigned int i = 0; i < int_array.size(); i++) {
		int_array[i] = i;
	}
	for (unsigned int i = 0; i < int_array_two.size(); i++) {
		int_array_two[i] = i * 2;
	}
	int_array_three = int_array;

	std::cout << "int_array.size(): " << int_array.size() << std::endl;
	for (unsigned int i = 0; i < int_array.size(); i++) {
		std::cout << int_array[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "int_array_two.size(): " << int_array_two.size() << std::endl;
	for (unsigned int i = 0; i < int_array_two.size(); i++) {
		std::cout << int_array_two[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "int_array_three.size(): " << int_array_three.size() << std::endl;
	for (unsigned int i = 0; i < int_array_three.size(); i++) {
		std::cout << int_array_three[i] << " ";
	}
	std::cout << std::endl;

	// system("leaks templates");
	return 0;
}
