/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:14 by mott              #+#    #+#             */
/*   Updated: 2024/10/25 15:06:01 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		int tmp = std::stoi(argv[i]);
		if (tmp < 0) {
			throw std::invalid_argument("Error: negativ number found");
		}
		_vector.push_back(tmp);
		_copy.push_back(tmp);
	}
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	(void)other;
}

PmergeMe::~PmergeMe() {
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
	}
	return *this;
}

// void PmergeMe::sort() {
// 	std::sort(_copy.begin(), _copy.end());
// }

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

void PmergeMe::build_pairs() {
	if (_copy.size() % 2 != 0) {
		_struggler = _copy.back();
		_copy.pop_back();
	}

	for (size_t i = 0; i < _copy.size(); i += 2) {
		_vector_pairs.push_back(std::pair<int, int>(_copy[i], _copy[i + 1]));
	}

	// while (_copy.size() > 0) {
	// 	_vector_pairs.push_back(std::pair<int, int>(_copy[0], _copy[1]));
	// 	_copy.erase(_copy.begin(), _copy.begin()+1);
	// }
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

void PmergeMe::build_chain() {
	for (auto pair : _vector_pairs) {
		_max_chain.push_back(pair.first);
		_min_chain.push_back(pair.second);
	}
}

void PmergeMe::print(const std::vector<int>& vector) const {
	for (int i : vector) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::print_pairs() const {
	for (const auto& pair : _vector_pairs) {
		std::cout << "[" << pair.first << ", " << pair.second << "] ";
	}
	std::cout << std::endl;

	if (_struggler != -1) {
		std::cout << "Struggler: " << _struggler << std::endl;
	}
}

const std::vector<int>& PmergeMe::get_vector() const {
	return _vector;
}

const std::vector<int>& PmergeMe::get_copy() const {
	return _copy;
}

const std::vector<int>& PmergeMe::get_jacobsthal() const {
	return _jacobsthal;
}

std::vector<std::pair<int, int>>& PmergeMe::get_vector_pairs() {
	return _vector_pairs;
}

const std::vector<int>& PmergeMe::get_max_chain() const {
	return _max_chain;
}
const std::vector<int>& PmergeMe::get_min_chain() const {
	return _min_chain;
}
