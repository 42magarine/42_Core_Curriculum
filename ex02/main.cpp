/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:25:38 by mott              #+#    #+#             */
/*   Updated: 2024/10/26 18:27:58 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << RED << "Usage: " << argv[0] << " <random numbers>" << RESET << std::endl;
	}

	try {
		PmergeMe ford_johnson(argc, argv);

		auto time_begin_my = std::chrono::high_resolution_clock::now();
		ford_johnson.my_sort();
		auto time_end_my = std::chrono::high_resolution_clock::now();

		auto time_begin_cpp = std::chrono::high_resolution_clock::now();
		ford_johnson.cpp_sort();
		auto time_end_cpp = std::chrono::high_resolution_clock::now();

		std::cout << "Before: ";
		ford_johnson.print(ford_johnson.get_vector_before());
		std::cout << std::endl;

		std::cout << "After:  ";
		ford_johnson.print(ford_johnson.get_vector_after());
		std::cout << std::endl;

		// std::cout << "Test:  ";
		// ford_johnson.print(ford_johnson.get_vector_test());
		// std::cout << std::endl;
		
		ford_johnson.compare();

		std::chrono::duration<double, std::micro> time_span_my = time_end_my - time_begin_my;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << time_span_my.count() << " µs" << std::endl;

		std::chrono::duration<double, std::micro> time_span_cpp = time_end_cpp - time_begin_cpp;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::sort() : " << time_span_cpp.count() << " µs" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}
