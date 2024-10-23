/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:16 by mott              #+#    #+#             */
/*   Updated: 2024/10/23 13:56:08 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <stdexcept>
#include <algorithm>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"

class PmergeMe {
	public:
		PmergeMe() = delete;
		PmergeMe(int argc, char** argv);
		PmergeMe(const PmergeMe& other);

		~PmergeMe();

		PmergeMe& operator=(const PmergeMe& other);

		void jacobsthal_numbers(int argc);
		void sort();
		void merge_sort(std::vector<int>& vector);
		void print(const std::vector<int>& vector) const;

		const std::vector<int>& get_vector() const;
		std::vector<int>& get_copy();
		const std::vector<int>& get_jacobsthal() const;

	private:
		std::vector<int> _vector;
		std::vector<int> _copy;
		std::vector<int> _jacobsthal;
};

#endif // PMERGEME_H

// shuf -i 1-100000 -n 3000 | tr "\n" " "
// jot -r 3000 1 100000 | tr '\n' ' '

// Seconds			s		1								Base time unit
// Milliseconds		ms		0.001 (1/1000)					1 ms = 0.001 s
// Microseconds		µs		0.000001 (1/1,000,000)			1 µs = 0.000001 s
// Nanoseconds		ns		0.000000001 (1/1,000,000,000)	1 ns = 0.000000001 s
