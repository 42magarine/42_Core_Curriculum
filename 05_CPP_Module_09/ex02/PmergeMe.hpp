/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:16 by mott              #+#    #+#             */
/*   Updated: 2024/10/30 12:09:18 by mott             ###   ########.fr       */
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
		void vector_binary_search(int number, int end);
		void vector_handle_straggler();

		void deque_input(int argc, char** argv);
		void deque_build_pairs();
		void deque_sort_pairs();
		void deque_merge_sort(std::deque<std::pair<int, int>>& deque_pairs);
		void deque_jacobsthal_numbers();
		void deque_build_main_chain();
		void deque_binary_search(int number, int end);
		void deque_handle_straggler();

		std::vector<int> _std_unsorted;
		std::vector<int> _std_sorted;

		std::vector<int> _vector_unsorted;
		std::vector<int> _vector_sorted;
		std::vector<std::pair<int, int>> _vector_pairs;
		int _vector_straggler = -1;
		std::vector<unsigned long> _vector_jacobsthal;

		std::deque<int> _deque_unsorted;
		std::deque<int> _deque_sorted;
		std::deque<std::pair<int, int>> _deque_pairs;
		int _deque_straggler = -1;
		std::deque<unsigned long> _deque_jacobsthal;
};

#endif // PMERGEME_H
