/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:14 by mott              #+#    #+#             */
/*   Updated: 2024/10/25 22:02:01 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char** argv) {
	_vector_before.reserve(argc - 1);
	_vector_after.reserve(argc - 1);
	_vector_test.reserve(argc - 1);

	for (int i = 1; i < argc; i++) {
		int n = std::stoi(argv[i]);
		if (n < 0) {
			throw std::invalid_argument("Error: negativ number found");
		}
		_vector_before.push_back(n);
		_vector_after.push_back(n);
		_vector_test.push_back(n);
	}
}

PmergeMe::~PmergeMe() {
}

void PmergeMe::cpp_sort() {
	std::sort(_vector_test.begin(), _vector_test.end());
}

void PmergeMe::my_sort() {
	build_pairs();
	sort_each_pair();
	merge_sort(_vector_pairs);
	build_main_chain();
}

void PmergeMe::build_pairs() {
	if (_vector_after.size() % 2 != 0) {
		_struggler = _vector_after.back();
		_vector_after.pop_back();
	}

	for (size_t i = 0; i < _vector_after.size(); i += 2) {
		_vector_pairs.emplace_back(_vector_after[i], _vector_after[i + 1]);
	}
	_vector_after.clear();
}

void PmergeMe::sort_each_pair() {
	for (auto& pair : _vector_pairs) {
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
		_vector_after.push_back(pair.first);
		_vector_tmp.push_back(pair.second);
	}

	for (int n : _vector_tmp) {
		binary_search(n);
	}
	if (_struggler != -1) {
		binary_search(_struggler);
	}
}

void PmergeMe::binary_search(int n) {
	int begin = 0;
	int end = _vector_after.size() - 1;

	while (begin < end) {
		int mid = (end - begin) / 2 + begin;

		if (n == _vector_after[mid]){
			begin = mid;
			break;
		}
		else if (n < _vector_after[mid]) {
			end = mid;
		}
		else { // n > _vector_after[mid]
			begin = mid + 1;
		}
	}
	_vector_after.insert(_vector_after.begin() + begin, n);
}

// 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, ...
void PmergeMe::jacobsthal_numbers(int argc) {
	_jacobsthal.push_back(0);
	_jacobsthal.push_back(1);

	int i = 2;
	while (true) {
		int next = _jacobsthal[i - 1] + 2 * _jacobsthal[i - 2];

		if (next < argc) {
			_jacobsthal.push_back(next);
			i++;
		}
		else {
			break;
		}
	}
}

void PmergeMe::compare() const {
	if (_vector_test == _vector_after) {
		std::cout << YELLOW << "OK" << RESET << std::endl;
	}
	else {
		std::cerr << RED << "Mismatch found" << RESET << std::endl;
	}
}

void PmergeMe::print(const std::vector<int>& vector) const {
	for (int i : vector) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

const std::vector<int>& PmergeMe::get_vector_before() const {
	return _vector_before;
}

const std::vector<int>& PmergeMe::get_vector_after() const {
	return _vector_after;
}
