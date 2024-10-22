/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:14 by mott              #+#    #+#             */
/*   Updated: 2024/10/22 18:23:03 by mott             ###   ########.fr       */
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

void PmergeMe::print() const {
	for (int i : _vector) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sort() {
	std::sort(_copy.begin(), _copy.end());

	for (int i : _copy) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
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
