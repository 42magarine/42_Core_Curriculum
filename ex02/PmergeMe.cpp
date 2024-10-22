/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:14 by mott              #+#    #+#             */
/*   Updated: 2024/10/22 14:19:23 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		_vector.push_back(std::stoi(argv[i]));
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
	std::vector<int> copy = _vector;
	std::sort(copy.begin(), copy.end());

	for (int i : copy) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

}
