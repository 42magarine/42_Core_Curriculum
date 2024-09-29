/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:24:12 by mott              #+#    #+#             */
/*   Updated: 2024/09/29 18:44:02 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	{
		int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
		size_t length = sizeof(array) / sizeof(array[0]);

		iter(array, length, print_array<int>);
		// void iter<int, void (*)(const int &i)>(int *array, size_t length, void (*func)(const int &i))
		std::cout << std::endl;
	}
	{
		char array[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
		size_t length = sizeof(array) / sizeof(array[0]);

		iter(array, length, print_array<char>);
		// void iter<char, void (*)(const char &i)>(char *array, size_t length, void (*func)(const char &i))
		std::cout << std::endl;
	}

	return 0;
}
