/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:52:48 by mott              #+#    #+#             */
/*   Updated: 2024/09/30 13:34:13 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// int main() {
// 	Array<int> int_array(10);
// 	Array<int> int_array_two(int_array);
// 	Array<int> int_array_three(int_array);

// 	for (unsigned int i = 0; i < int_array.size(); i++) {
// 		int_array[i] = i;
// 	}
// 	for (unsigned int i = 0; i < int_array_two.size(); i++) {
// 		int_array_two[i] = i * 2;
// 	}
// 	int_array_three = int_array;

// 	std::cout << "int_array.size(): " << int_array.size() << std::endl;
// 	for (unsigned int i = 0; i < int_array.size(); i++) {
// 		std::cout << int_array[i] << " ";
// 	}
// 	std::cout << std::endl;

// 	std::cout << "int_array_two.size(): " << int_array_two.size() << std::endl;
// 	for (unsigned int i = 0; i < int_array_two.size(); i++) {
// 		std::cout << int_array_two[i] << " ";
// 	}
// 	std::cout << std::endl;

// 	std::cout << "int_array_three.size(): " << int_array_three.size() << std::endl;
// 	for (unsigned int i = 0; i < int_array_three.size(); i++) {
// 		std::cout << int_array_three[i] << " ";
// 	}
// 	std::cout << std::endl;

// 	system("leaks templates");
// 	return 0;
// }

// int main() {
// 	int* a = new int();
// 	std::cout << *a << std::endl;
// 	delete a;

// 	return 0;
// }

// int main() {
// 	Array<char> array_one(26);

// 	for (unsigned int i = 0; i < array_one.size(); i++) {
// 		array_one[i] = 'a' + i;
// 	}
// 	for (unsigned int i = 0; i < array_one.size(); i++) {
// 		std::cout << array_one[i] << " ";
// 	}
// 	std::cout << std::endl;

// 	try {
// 		std::cout << array_one[100] << std::endl;
// 	}
// 	catch (std::exception& e) {
// 		std::cout << e.what() << std::endl;
// 	}

// 	return 0;
// }

int main() {
	Array<std::string> array_one(8);

	for (unsigned int i = 0; i < array_one.size(); i++) {
		array_one[i] = "string_" + std::to_string(i);
	}
	for (unsigned int i = 0; i < array_one.size(); i++) {
		std::cout << array_one[i] << " ";
	}
	std::cout << std::endl;

	try {
		std::cout << array_one[100] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
