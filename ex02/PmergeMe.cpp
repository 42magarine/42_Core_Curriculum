/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:14 by mott              #+#    #+#             */
/*   Updated: 2024/10/29 14:05:15 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
}

void PmergeMe::vector_sort(int argc, char** argv) {
	vector_input(argc, argv);
	vector_build_pairs();
	vector_sort_pairs();
	merge_sort(_vector_pairs);
	build_main_chain();
}

void PmergeMe::deque_sort(int argc, char** argv) {
	deque_input(argc, argv);
	deque_build_pairs();
	deque_sort_pairs();
	// merge_sort(_vector_pairs);
	// build_main_chain();
}

void PmergeMe::std_sort(int argc, char** argv) {
	_std_unsorted.reserve(argc - 1);
	_std_sorted.reserve(argc - 1);
	int number;

	for (int i = 1; i < argc; i++) {
		number = std::stoi(argv[i]);
		if (number < 0) {
			throw std::invalid_argument("Error: negativ number found");
		}
		_std_unsorted.push_back(number);
		_std_sorted.push_back(number);
	}
	std::sort(_std_sorted.begin(), _std_sorted.end());
}

void PmergeMe::vector_input(int argc, char** argv) {
	_vector_unsorted.reserve(argc - 1);
	_vector_sorted.reserve(argc - 1);
	int number;

	for (int i = 1; i < argc; i++) {
		number = std::stoi(argv[i]);
		if (number < 0) {
			throw std::invalid_argument("Error: negativ number found");
		}
		_vector_unsorted.push_back(number);
	}
}

void PmergeMe::deque_input(int argc, char** argv) {
	int number;

	for (int i = 1; i < argc; i++) {
		number = std::stoi(argv[i]);
		if (number < 0) {
			throw std::invalid_argument("Error: negative number found");
		}
		_deque_unsorted.push_back(number);
	}
}

void PmergeMe::vector_build_pairs() {
	if (_vector_unsorted.size() % 2 != 0) {
		_vector_straggler = _vector_unsorted.back();
		_vector_unsorted.pop_back();
	}

	for (size_t i = 0; i < _vector_unsorted.size(); i += 2) {
		_vector_pairs.emplace_back(_vector_unsorted[i], _vector_unsorted[i + 1]);
	}
}

void PmergeMe::deque_build_pairs() {
	if (_deque_unsorted.size() % 2 != 0) {
		_deque_straggler = _deque_unsorted.back();
		_deque_unsorted.pop_back();
	}

	for (size_t i = 0; i < _deque_unsorted.size(); i += 2) {
		_deque_pairs.emplace_back(_deque_unsorted[i], _deque_unsorted[i + 1]);
	}
}

void PmergeMe::vector_sort_pairs() {
	for (auto& pair : _vector_pairs) {
		if (pair.first < pair.second) {
			std::swap(pair.first, pair.second);
		}
	}
}

void PmergeMe::deque_sort_pairs() {
	for (auto& pair : _deque_pairs) {
		if (pair.first < pair.second) {
			std::swap(pair.first, pair.second);
		}
	}
}


void PmergeMe::merge_sort(std::vector<std::pair<int, int>>& vector_pairs) {
	if (vector_pairs.size() < 2) {
		return;
	}

	int mid = vector_pairs.size() / 2;
	std::vector<std::pair<int, int>> left(vector_pairs.begin(), vector_pairs.begin() + mid);
	std::vector<std::pair<int, int>> right(vector_pairs.begin() + mid, vector_pairs.end());

	merge_sort(left);
	merge_sort(right);

	size_t i = 0, j = 0, k = 0;

	while (i < left.size() && j < right.size()) {
		if (left[i].first < right[j].first) {
			vector_pairs[k++] = left[i++];
		}
		else {
			vector_pairs[k++] = right[j++];
		}
	}

	while (i < left.size()) {
		vector_pairs[k++] = left[i++];
	}

	while (j < right.size()) {
		vector_pairs[k++] = right[j++];
	}
}

void PmergeMe::build_main_chain() {

	for (const auto& pair : _vector_pairs) {
		_vector_sorted.push_back(pair.first);
		_vector_tmp.push_back(pair.second);
	}

	jacobsthal_numbers(_vector_tmp.size());
	// print(_jacobsthal);

	_vector_sorted.insert(_vector_sorted.begin(), _vector_tmp[0]);

	// for (int n : _vector_tmp) {
	// for (size_t i = 1; i < _vector_tmp.size(); i++) {
	// 	binary_search(_vector_tmp[i]);
		// binary_search(_vector_tmp[i], i + i);
	// }

	int i = 3;
	int count = 1;
	size_t last_j = _jacobsthal[i - 1] - 1; // -1 for right index
	size_t curr_j = _jacobsthal[i] - 1; // -1 for right index

	while (last_j < curr_j && last_j < _vector_tmp.size()) {
		// std::cout << YELLOW << "index: " << curr_j << RESET << std::endl;
		binary_search(_vector_tmp[curr_j], count + curr_j); // i sollte jede loop erhöht werden
		curr_j--;
		count++;
		if (last_j == curr_j) {
			i++; // hier muss i nur erhöht werden, wenn ich eine neue jacobsthal zahl brauche
			last_j = _jacobsthal[i - 1] - 1;
			curr_j = _jacobsthal[i] - 1;
			if (curr_j >= _vector_tmp.size()) {
				curr_j = _vector_tmp.size() - 1;
			}
		}
	}

	if (_vector_straggler != -1) {
		// binary_search(_vector_straggler);
		binary_search(_vector_straggler, _vector_sorted.size());
	}
}

// void PmergeMe::binary_search(int n) {
void PmergeMe::binary_search(int n, int end) {
	int begin = 0;
	// int end = _vector_sorted.size() - 1;
	// std::cout << "end: " << end << std::endl;

	while (begin < end) {
		int mid = (end - begin) / 2 + begin;

		if (n == _vector_sorted[mid]){
			begin = mid;
			break;
		}
		else if (n < _vector_sorted[mid]) {
			end = mid;
		}
		else { // n > _vector_sorted[mid]
			begin = mid + 1;
		}
	}
	// print(_vector_sorted);
	// print(_vector_tmp);
	_vector_sorted.insert(_vector_sorted.begin() + begin, n);
	// std::cout << YELLOW << "n: " << n << RESET << std::endl;
	// print(_vector_sorted);
	// std::cout << std::endl;
}

// 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, ...
void PmergeMe::jacobsthal_numbers(int n) {
	_jacobsthal.push_back(0);
	_jacobsthal.push_back(1);

	int i = 2;
	// while (true) {
	// 	int next = _jacobsthal[i - 1] + 2 * _jacobsthal[i - 2];

	// 	if (next < n) {
	// 		_jacobsthal.push_back(next);
	// 		i++;
	// 	}
	// 	else {
	// 		break;
	// 	}
	// }

	while (_jacobsthal.back() < n) {
		int next = _jacobsthal[i - 1] + 2 * _jacobsthal[i - 2];
		_jacobsthal.push_back(next);
		i++;
	}
}

void PmergeMe::compare() const {
	if (_std_sorted == _vector_sorted) {
		std::cout << YELLOW << "OK" << RESET << std::endl;
	}
	else {
		std::cerr << RED << "Mismatch found" << RESET << std::endl;
	}
}

void PmergeMe::print_before() const {
	for (int i : _std_unsorted) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::print_after() const {
	for (int i : _vector_unsorted) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
