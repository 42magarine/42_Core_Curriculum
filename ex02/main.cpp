/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:25:38 by mott              #+#    #+#             */
/*   Updated: 2024/10/29 13:33:14 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << RED << "Usage: " << argv[0] << " <random numbers>" << RESET << std::endl;
		return 1;
	}

	PmergeMe ford_johnson;

	try {
		auto vector_time_begin = std::chrono::high_resolution_clock::now();
		ford_johnson.vector_sort(argc, argv);
		auto vector_time_end = std::chrono::high_resolution_clock::now();

		auto deque_time_begin = std::chrono::high_resolution_clock::now();
		ford_johnson.deque_sort(argc, argv);
		auto deque_time_end = std::chrono::high_resolution_clock::now();

		auto std_time_begin = std::chrono::high_resolution_clock::now();
		ford_johnson.std_sort(argc, argv);
		auto std_time_end = std::chrono::high_resolution_clock::now();

		std::cout << "Before: ";
		ford_johnson.print_before();
		std::cout << std::endl;

		std::cout << "After:  ";
		ford_johnson.print_after();
		std::cout << std::endl;

		ford_johnson.compare();

		std::chrono::duration<double, std::micro> vector_time_span = vector_time_end - vector_time_begin;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vector_time_span.count() << " µs" << std::endl;

		std::chrono::duration<double, std::micro> deque_time_span = deque_time_end - deque_time_begin;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque() : " << deque_time_span.count() << " µs" << std::endl;

		std::chrono::duration<double, std::micro> std_time_span = std_time_end - std_time_begin;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::sort() : " << std_time_span.count() << " µs" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}
