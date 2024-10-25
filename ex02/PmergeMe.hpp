/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:16 by mott              #+#    #+#             */
/*   Updated: 2024/10/25 21:27:59 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <stdexcept>
#include <algorithm>
#include <utility>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"

class PmergeMe {
	public:
		PmergeMe() = delete;
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& other) = delete;

		~PmergeMe();

		PmergeMe& operator=(const PmergeMe& other) = delete;

		void cpp_sort();
		void my_sort();
		void compare() const;
		void print(const std::vector<int>& vector) const;
		const std::vector<int>& get_vector_before() const;
		const std::vector<int>& get_vector_after() const;

	private:
		void build_pairs();
		void sort_each_pair();
		void merge_sort(std::vector<std::pair<int, int>>& vector_pairs);
		void build_main_chain();
		void binary_search(int target);
		void jacobsthal_numbers(int argc);

		std::vector<int> _vector_before;
		std::vector<int> _vector_after;
		std::vector<int> _vector_test;
		std::vector<int> _vector_tmp;

		std::vector<int> _jacobsthal;
		std::vector<std::pair<int, int>> _vector_pairs;
		int _struggler = -1;
};

#endif // PMERGEME_H


// shuf -i 1-100000 -n 3000 | tr "\n" " "
// jot -r 3000 1 100000 | tr '\n' ' '


// Seconds			s		1								Base time unit
// Milliseconds		ms		0.001 (1/1000)					1 ms = 0.001 s
// Microseconds		µs		0.000001 (1/1,000,000)			1 µs = 0.000001 s
// Nanoseconds		ns		0.000000001 (1/1,000,000,000)	1 ns = 0.000000001 s


// 1. Group elements into pairs:
// 	Divide the list of elements into pairs, resulting in [n/2] pairs of elements.

// 2. Identify the larger element in each pair:
// 	For each pair, determine the larger of the two elements.

// 3. Recursively sort the larger elements:
// 	Recursively apply the algorithm to the list of the larger elements obtained from the previous step.

// 4. Create the main chain:
// 	Establish the main chain that will hold the sorted elements.

// 5. Generate the order of insertion using Jacobsthal numbers:
// 	Use Jacobsthal numbers to determine the sequence in which elements will be inserted into the main chain.

// 6. Insert elements into the main chain:
// 	Insert the elements from the order determined by the Jacobsthal numbers into the main chain.

// 7. Handle Stragglers:
// 	Address any elements that did not fit into the initial pairings or order.

// 7. Handle the Straggler:
// 	If the input list contains an odd number of elements, the last unpaired element is referred to as the "straggler."
