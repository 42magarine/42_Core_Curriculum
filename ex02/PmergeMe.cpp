/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:14 by mott              #+#    #+#             */
/*   Updated: 2024/10/23 14:06:28 by mott             ###   ########.fr       */
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

void PmergeMe::sort() {
	std::sort(_copy.begin(), _copy.end());
}

// void PmergeMe::merge_sort(std::vector<int>& vector) {
// 	if (vector.size() < 2) {
// 		return;
// 	}

// 	int mid = vector.size() / 2;
// 	std::vector<int> left(vector.begin(), vector.begin() + mid);
// 	std::vector<int> right(vector.begin() + mid, vector.end());

// 	merge_sort(left);
// 	merge_sort(right);

// 	size_t i = 0, j = 0, k = 0;

// 	while (i < left.size() && j < right.size()) {
// 		if (left[i] < right[j]) {
// 			vector[k] = left[i];
// 			i++;
// 		}
// 		else {
// 			vector[k] = right[j];
// 			j++;
// 		}
// 		k++;
// 	}

// 	while (i < left.size()) {
// 		vector[k] = left[i];
// 		i++;
// 		k++;
// 	}

// 	while (j < right.size()) {
// 		vector[k] = right[j];
// 		j++;
// 		k++;
// 	}
// }

void PmergeMe::print(const std::vector<int>& vector) const {
	for (int i : vector) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
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


// std::vector<int> _vector = {8, 1, 6, 5, 2, 3, 4, 7};

// std::pair<int, int> _pair_1_8 = {1, 8};
// std::pair<int, int> _pair_5_6 = {5, 6};
// std::pair<int, int> _pair_2_3 = {2, 3};
// std::pair<int, int> _pair_4_7 = {4, 7};

// std::pair<int, int> _pair_2_3 = {2, 3};
// std::pair<int, int> _pair_5_6 = {5, 6};
// std::pair<int, int> _pair_4_7 = {4, 7};
// std::pair<int, int> _pair_1_8 = {1, 8};

// std::vector<int> _vector = {2, 3, 6, 7, 8};

// if (4 < 2)
// else if (4 < 3)
// else if (4 < 6)
// else

// std::vector<int> _vector = {2, 3, 4, 6, 7, 8};

// if (5 < 2)
// else if (5 < 3)
// else if (5 < 4)
// else

// std::vector<int> _vector = {2, 3, 4, 5, 6, 7, 8};

// if (1 < 5)
// 	if (1 < 3)
// 		if (1 < 2)
// 		else
// 	else if (1 < 4)
// 	else
// else if (1 < 7)
// 	if (1 < 6)
// 	else
// else
