/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:16 by mott              #+#    #+#             */
/*   Updated: 2024/10/29 17:31:27 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <chrono>
#include <algorithm>
#include <utility>
#include <stdexcept>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other) = delete;
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other) = delete;

		void vector_sort(int argc, char** argv);
		void deque_sort(int argc, char** argv);
		void std_sort(int argc, char** argv);

		void print_before() const;
		void print_after() const;
		void compare() const;

	private:
		void vector_input(int argc, char** argv);
		void vector_build_pairs();
		void vector_sort_pairs();
		void vector_merge_sort(std::vector<std::pair<int, int>>& vector_pairs);
		void vector_jacobsthal_numbers();
		void vector_build_main_chain();

		void deque_input(int argc, char** argv);
		void deque_build_pairs();
		void deque_sort_pairs();
		void deque_merge_sort(std::deque<std::pair<int, int>>& deque_pairs);
		void deque_jacobsthal_numbers();
		void deque_build_main_chain();


		// void binary_search(int n);
		void binary_search(int n, int end);


		std::vector<int> _std_unsorted;
		std::vector<int> _std_sorted;

		std::vector<int> _vector_unsorted;
		std::vector<int> _vector_sorted;
		std::vector<std::pair<int, int>> _vector_pairs;
		int _vector_straggler = -1;
		std::vector<int> _vector_jacobsthal;

		std::deque<int> _deque_unsorted;
		std::deque<int> _deque_sorted;
		std::deque<std::pair<int, int>> _deque_pairs;
		int _deque_straggler = -1;
		std::deque<int> _deque_jacobsthal;
};

#endif // PMERGEME_H


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
