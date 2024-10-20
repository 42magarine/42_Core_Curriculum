/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:28:56 by mott              #+#    #+#             */
/*   Updated: 2024/10/20 19:05:20 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& input_file) {
	std::ifstream data_file(DATA_FILE);
	if (!data_file.is_open()) {
		throw std::runtime_error(RED "Could not open " DATA_FILE RESET);
	}

	std::string line;
	while (std::getline(data_file, line)) {
		size_t delim = line.find(',');
		if (delim == std::string::npos) {
			std::cerr << RED DATA_FILE << ": Invalid format in line: " RESET << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, delim);
		// check for valid date? YYYY-MM-DD
		try {
			float value = std::stof(line.substr(delim + 1));
			// check value between 0 ans 1000
			_data[date] = value;
		}
		catch (const std::exception& e) {
			std::cerr << RED DATA_FILE << ": Invalid number in line: " RESET << line << std::endl;
			continue;
		}
	}
	
	data_file.close();
	print_map();
	(void)input_file;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	(void)other;
	// std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	// std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		// std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

void BitcoinExchange::print_map() const {
	// for (const std::pair<const std::string, float>& entry : _data) {
	for (const auto& entry : _data) {
		std::cout << entry.first << " => " << entry.second << std::endl;
	}
}
