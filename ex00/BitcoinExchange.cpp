#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}
