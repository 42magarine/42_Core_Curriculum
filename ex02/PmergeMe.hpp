#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);

		~PmergeMe();

		PmergeMe& operator=(const PmergeMe& other);

	private:
};

#endif // PMERGEME_H
