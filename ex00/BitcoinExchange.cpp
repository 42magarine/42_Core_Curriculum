/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:28:56 by mott              #+#    #+#             */
/*   Updated: 2024/10/20 20:44:51 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
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
			// check for valid value? >=0
			_data[date] = value;
		}
		catch (const std::exception& e) {
			std::cerr << RED DATA_FILE << ": Invalid number in line: " RESET << line << std::endl;
		}
	}
	data_file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	(void)other;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
	}
	return *this;
}

void BitcoinExchange::print_map() const {
	// for (const std::pair<const std::string, float>& entry : _data) {
	for (const auto& entry : _data) {
		std::cout << entry.first << " => " << entry.second << std::endl;
	}
}

void BitcoinExchange::calculate_values(const std::string& argv) {
	std::ifstream input_file(argv);
	if (!input_file.is_open()) {
		throw std::runtime_error(RED "Could not open " + argv + RESET);
	}

	std::string line;
	while (std::getline(input_file, line)) {
		size_t delim = line.find('|');
		if (delim == std::string::npos) {
			std::cerr << RED << ": Invalid format in line: " RESET << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, delim);
		float value;
		// check for valid date? YYYY-MM-DD
		try {
			value = std::stof(line.substr(delim + 1));
			// check for valid value? between 0 and 1000
		}
		catch (const std::exception& e) {
			std::cerr << RED << ": Invalid number in line: " RESET << line << std::endl;
		}

		// std::map<std::string, float>::iterator itup = _data.upper_bound(date);
		auto itup = _data.upper_bound(date);
		if (itup == _data.begin()) {
			std::cout << date << " => " << value << " = " << "no value" << std::endl;
		}
		else {
			itup--;
			std::cout << date << " => " << value << " = " << itup->second * value << std::endl;
		}
	}
}
