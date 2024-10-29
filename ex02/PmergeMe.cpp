/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:14 by mott              #+#    #+#             */
/*   Updated: 2024/10/29 21:16:16 by mott             ###   ########.fr       */
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
	if (_vector_pairs.size() > 0) {
		vector_sort_pairs();
		vector_merge_sort(_vector_pairs);
		vector_jacobsthal_numbers();
		vector_build_main_chain();
	}
	vector_handle_straggler();
}

void PmergeMe::deque_sort(int argc, char** argv) {
	deque_input(argc, argv);
	deque_build_pairs();
	if (_deque_pairs.size() > 0) {
		deque_sort_pairs();
		deque_merge_sort(_deque_pairs);
		deque_jacobsthal_numbers();
		deque_build_main_chain();
	}
	deque_handle_straggler();
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

	_vector_pairs.reserve(_vector_unsorted.size() / 2);

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

void PmergeMe::vector_merge_sort(std::vector<std::pair<int, int>>& vector_pairs) {
	if (vector_pairs.size() < 2) {
		return;
	}

	auto mid = vector_pairs.begin() + (vector_pairs.size() / 2);
	std::vector<std::pair<int, int>> left(vector_pairs.begin(), mid);
	std::vector<std::pair<int, int>> right(mid, vector_pairs.end());

	vector_merge_sort(left);
	vector_merge_sort(right);

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

void PmergeMe::deque_merge_sort(std::deque<std::pair<int, int>>& deque_pairs) {
	if (deque_pairs.size() < 2) {
		return;
	}

	auto mid = deque_pairs.begin() + (deque_pairs.size() / 2);
	std::deque<std::pair<int, int>> left(deque_pairs.begin(), mid);
	std::deque<std::pair<int, int>> right(mid, deque_pairs.end());

	deque_merge_sort(left);
	deque_merge_sort(right);

	size_t i = 0, j = 0, k = 0;

	while (i < left.size() && j < right.size()) {
		if (left[i].first < right[j].first) {
			deque_pairs[k++] = left[i++];
		}
		else {
			deque_pairs[k++] = right[j++];
		}
	}

	while (i < left.size()) {
		deque_pairs[k++] = left[i++];
	}
	while (j < right.size()) {
		deque_pairs[k++] = right[j++];
	}
}

// 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, ...
void PmergeMe::vector_jacobsthal_numbers() {
	_vector_jacobsthal.push_back(0);
	_vector_jacobsthal.push_back(1);

	int next;
	int i = 2;

	while (_vector_jacobsthal.back() < _vector_pairs.size()) {
		next = _vector_jacobsthal[i - 1] + 2 * _vector_jacobsthal[i - 2];
		_vector_jacobsthal.push_back(next);
		i++;
	}
}

void PmergeMe::deque_jacobsthal_numbers() {
	_deque_jacobsthal.push_back(0);
	_deque_jacobsthal.push_back(1);

	int next;
	int i = 2;

	while (_deque_jacobsthal.back() < _deque_pairs.size()) {
		next = _deque_jacobsthal[i - 1] + 2 * _deque_jacobsthal[i - 2];
		_deque_jacobsthal.push_back(next);
		i++;
	}
}

void PmergeMe::vector_build_main_chain() {
	for (const auto& pair : _vector_pairs) {
		_vector_sorted.push_back(pair.first);
	}

	_vector_sorted.insert(_vector_sorted.begin(), _vector_pairs[0].second);
	int numbers_added = 1;

	if (_vector_pairs.size() < 2) {
		return;
	}

	auto it = _vector_jacobsthal.begin() + 3;
	size_t current_index;
	size_t previous_index = 0;

	do {
		current_index = *it - 1;
		if (current_index >= _vector_pairs.size()) {
			current_index = _vector_pairs.size() - 1;
		}

		while (current_index > previous_index) {
			vector_binary_search(_vector_pairs[current_index].second, current_index + numbers_added);
			current_index--;
			numbers_added++;
		}
		previous_index = *it - 1;
		it++;
	} while (it != _vector_jacobsthal.end());
}

void PmergeMe::deque_build_main_chain() {
	for (const auto& pair : _deque_pairs) {
		_deque_sorted.push_back(pair.first);
	}

	_deque_sorted.insert(_deque_sorted.begin(), _deque_pairs[0].second);
	int numbers_added = 1;

	if (_deque_pairs.size() < 2) {
		return;
	}

	auto it = _deque_jacobsthal.begin() + 3;
	size_t current_index;
	size_t previous_index = 0;

	do {
		current_index = *it - 1;
		if (current_index >= _deque_pairs.size()) {
			current_index = _deque_pairs.size() - 1;
		}

		while (current_index > previous_index) {
			deque_binary_search(_deque_pairs[current_index].second, current_index + numbers_added);
			current_index--;
			numbers_added++;
		}
		previous_index = *it - 1;
		it++;
	} while (it != _deque_jacobsthal.end());
}

void PmergeMe::vector_handle_straggler() {
	if (_vector_straggler != -1) {
		vector_binary_search(_vector_straggler, _vector_sorted.size());
	}
}

void PmergeMe::deque_handle_straggler() {
	if (_deque_straggler != -1) {
		deque_binary_search(_deque_straggler, _deque_sorted.size());
	}
}

void PmergeMe::vector_binary_search(int number, int end) {
	int begin = 0;

	while (begin < end) {
		int mid = (end - begin) / 2 + begin;

		if (number == _vector_sorted[mid]){
			begin = mid;
			break;
		}
		else if (number < _vector_sorted[mid]) {
			end = mid;
		}
		else {
			begin = mid + 1;
		}
	}
	_vector_sorted.insert(_vector_sorted.begin() + begin, number);
}

void PmergeMe::deque_binary_search(int number, int end) {
	int begin = 0;

	while (begin < end) {
		int mid = (end - begin) / 2 + begin;

		if (number == _deque_sorted[mid]){
			begin = mid;
			break;
		}
		else if (number < _deque_sorted[mid]) {
			end = mid;
		}
		else {
			begin = mid + 1;
		}
	}
	_deque_sorted.insert(_deque_sorted.begin() + begin, number);
}

void PmergeMe::compare() const {
	if (_std_sorted == _vector_sorted) {
		std::cout << YELLOW << "std::vector: OK" << RESET << std::endl;
	}
	else {
		std::cerr << RED << "std::vector: KO" << RESET << std::endl;
	}

	if (_std_sorted == (std::vector<int>(_deque_sorted.begin(), _deque_sorted.end()))) {
		std::cout << YELLOW << "std::deque: OK" << RESET << std::endl;
	}
	else {
		std::cerr << RED << "std::deque: KO" << RESET << std::endl;
	}
}

void PmergeMe::print_before() const {
	std::cout << YELLOW << "Before: " << RESET << std::endl;
	for (int i : _std_unsorted) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::print_after() const {
	std::cout << YELLOW << "After: " << RESET << std::endl;
	for (int i : _vector_unsorted) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}
