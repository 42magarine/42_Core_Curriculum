/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:16 by mott              #+#    #+#             */
/*   Updated: 2024/10/22 14:18:35 by mott             ###   ########.fr       */
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

		void print() const;
		void sort();

	private:
		std::vector<int> _vector;
};

#endif // PMERGEME_H

// Seconds			s		1								Base time unit
// Milliseconds		ms		0.001 (1/1000)					1 ms = 0.001 s
// Microseconds		µs		0.000001 (1/1,000,000)			1 µs = 0.000001 s
// Nanoseconds		ns		0.000000001 (1/1,000,000,000)	1 ns = 0.000000001 s
