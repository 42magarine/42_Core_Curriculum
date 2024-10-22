/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:25:38 by mott              #+#    #+#             */
/*   Updated: 2024/10/22 14:19:38 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << RED << "Usage: " << argv[0] << " <random numbers>" << RESET << std::endl;
	}

	auto time_begin = std::chrono::high_resolution_clock::now();

	try {
		PmergeMe ford_johnson(argc, argv);
		ford_johnson.print();
		ford_johnson.sort();
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}

	auto time_end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time_span = time_end - time_begin;
	std::cout << "time_span: " << time_span.count() << " s" << std::endl;
	std::chrono::duration<double, std::milli> time_span2 = time_end - time_begin;
	std::cout << "time_span: " << time_span2.count() << " ms" << std::endl;
	std::chrono::duration<double, std::micro> time_span3 = time_end - time_begin;
	std::cout << "time_span: " << time_span3.count() << " us" << std::endl;
	std::chrono::duration<double, std::nano> time_span4 = time_end - time_begin;
	std::cout << "time_span: " << time_span4.count() << " ns" << std::endl;

	// std::cout << "Before: ";
	// for (int i = 1; i < argc; i++) {
	// 	std::cout << argv[i] << " ";
	// }
	// std::cout << std::endl;

	// std::cout << "After:  ";
	// for (int i = 1; i < argc; i++) {
	// 	std::cout << argv[i] << " ";
	// }
	// std::cout << std::endl;

	// std::cout << "Time to process a range of " << argc - 1 << " elements with std::[..] : " << "0.001" << " us" << std::endl;

	// std::cout << "Time to process a range of " << argc - 1 << " elements with std::[..] : " << "0.001" << " us" << std::endl;

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
