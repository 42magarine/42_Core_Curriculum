#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

PmergeMe::~PmergeMe() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}
