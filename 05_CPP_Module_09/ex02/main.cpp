/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:25:38 by mott              #+#    #+#             */
/*   Updated: 2024/10/30 12:32:11 by mott             ###   ########.fr       */
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

		ford_johnson.print_before();
		ford_johnson.print_after();
		ford_johnson.compare();

		std::chrono::duration<double, std::micro> vector_time_span = vector_time_end - vector_time_begin;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << vector_time_span.count() << " µs" << std::endl;

		std::chrono::duration<double, std::micro> deque_time_span = deque_time_end - deque_time_begin;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << deque_time_span.count() << " µs" << std::endl;

		std::chrono::duration<double, std::micro> std_time_span = std_time_end - std_time_begin;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::sort: " << std_time_span.count() << " µs" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}

// Seconds			s		1								Base time unit
// Milliseconds		ms		0.001 (1/1000)					1 ms = 0.001 s
// Microseconds		µs		0.000001 (1/1,000,000)			1 µs = 0.000001 s
// Nanoseconds		ns		0.000000001 (1/1,000,000,000)	1 ns = 0.000000001 s
