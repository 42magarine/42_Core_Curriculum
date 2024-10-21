/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:25:38 by mott              #+#    #+#             */
/*   Updated: 2024/10/21 21:17:28 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << RED << "Usage: " << argv[0] << " <random numbers>" << RESET << std::endl;
	}

	std::cout << "Before: ";
	for (int i = 1; i < argc; i++) {
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "After:  ";
	for (int i = 1; i < argc; i++) {
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::[..] : " << "0.001" << " us" << std::endl;

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::[..] : " << "0.001" << " us" << std::endl;

	return 0;
}


// shuf -i 1-100000 -n 3000 | tr "\n" " "
// jot -r 3000 1 100000 | tr '\n' ' '


// long long jabocsthal_number(long long i) {
// 	if (i == 0) {
// 		return 0;
// 	}
// 	else if (i == 1) {
// 		return 1;
// 	}
// 	else {
// 		return jabocsthal_number(i - 1) + 2 * jabocsthal_number(i - 2);
// 	}
// }
