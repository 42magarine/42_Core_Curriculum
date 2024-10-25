/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:25:38 by mott              #+#    #+#             */
/*   Updated: 2024/10/25 20:13:51 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cerr << RED << "Usage: " << argv[0] << " <random numbers>" << RESET << std::endl;
	}

	try {
		PmergeMe ford_johnson(argc, argv);
		ford_johnson.sort();
		// ford_johnson.print(ford_johnson.get_jacobsthal());
		// ford_johnson.print(ford_johnson.get_vector());
		// ford_johnson.print(ford_johnson.get_copy());
		auto time_begin = std::chrono::high_resolution_clock::now();
		ford_johnson.jacobsthal_numbers(argc);
		ford_johnson.build_pairs();
		// ford_johnson.print_pairs();
		ford_johnson.sort_each_pair();
		// ford_johnson.print_pairs();
		ford_johnson.merge_sort(ford_johnson.get_vector_pairs());
		// ford_johnson.print_pairs();
		ford_johnson.build_chain();
		// ford_johnson.print(ford_johnson.get_max_chain());
		// ford_johnson.print(ford_johnson.get_min_chain());
		ford_johnson.build_main_chain();
		// ford_johnson.print(ford_johnson.get_copy_test());
		// ford_johnson.print(ford_johnson.get_main_chain());

		auto time_end = std::chrono::high_resolution_clock::now();

		ford_johnson.compare();

		std::chrono::duration<double> time_span = time_end - time_begin;
		std::cout << "time_span: " << time_span.count() << " s" << std::endl;
		std::chrono::duration<double, std::milli> time_span2 = time_end - time_begin;
		std::cout << "time_span: " << time_span2.count() << " ms" << std::endl;
		std::chrono::duration<double, std::micro> time_span3 = time_end - time_begin;
		std::cout << "time_span: " << time_span3.count() << " us" << std::endl;
		std::chrono::duration<double, std::nano> time_span4 = time_end - time_begin;
		std::cout << "time_span: " << time_span4.count() << " ns" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}



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
