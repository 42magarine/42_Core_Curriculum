/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:14 by mott              #+#    #+#             */
/*   Updated: 2024/10/25 21:12:55 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		int tmp = std::stoi(argv[i]);
		if (tmp < 0) {
			throw std::invalid_argument("Error: negativ number found");
		}
		_vector_before.push_back(tmp);
		_vector_after.push_back(tmp);
		_vector_test.push_back(tmp);
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
		_vector_pairs.push_back(std::pair<int, int>(_vector_after[i], _vector_after[i + 1]));
	}
}

void PmergeMe::sort_each_pair() {
	for (size_t i = 0; i < _vector_pairs.size(); i++) {
		if (_vector_pairs[i].first < _vector_pairs[i].second) {
			std::swap(_vector_pairs[i].first, _vector_pairs[i].second);
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
			vector_pairs[k] = left[i];
			i++;
		}
		else {
			vector_pairs[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left.size()) {
		vector_pairs[k] = left[i];
		i++;
		k++;
	}

	while (j < right.size()) {
		vector_pairs[k] = right[j];
		j++;
		k++;
	}
}

void PmergeMe::build_main_chain() {
	_vector_after.clear();
	for (auto pair : _vector_pairs) {
		_vector_after.push_back(pair.first);
		_vector_tmp.push_back(pair.second);
	}

	for (int number : _vector_tmp) {
		binary_search(number);
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

// 0, 1, 1, 3, 5, 11, 21
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

void PmergeMe::compare() {
	for (size_t i = 0; i < _vector_test.size(); i++) {
		if (_vector_test[i] != _vector_after[i]) {
			std::cerr << RED << _vector_test[i] << " != " << _vector_after[i] << RESET << std::endl;
			return;
		}
	}
	std::cout << YELLOW << "OK" << RESET << std::endl;
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
