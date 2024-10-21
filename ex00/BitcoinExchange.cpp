/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:28:56 by mott              #+#    #+#             */
/*   Updated: 2024/10/21 15:04:34 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream data_file(DATA_FILE);
	if (!data_file.is_open()) {
		throw std::runtime_error(RED DATA_FILE ": Could not open file." RESET);
	}

	std::string header;
	std::getline(data_file, header);

	std::string line;
	while (std::getline(data_file, line)) {
		size_t delim = line.find(',');
		if (delim == std::string::npos) {
			std::cerr << RED << DATA_FILE << ": Invalid format in line: " << line << RESET << std::endl;
			continue;
		}

		std::string date = line.substr(0, delim);
		float value;

		try {
			value = std::stof(line.substr(delim + 1));
		}
		catch (const std::exception& e) {
			std::cerr << RED << DATA_FILE << ": Invalid number in line: " << line << RESET << std::endl;
			continue;
		}

		if (value < 0) {
			std::cerr << RED << DATA_FILE << ": Invalid value in line: " << line << RESET << std::endl;
			continue;
		}
		_data[date] = value;
	}
	data_file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_data = other._data;
	}
	return *this;
}

void BitcoinExchange::calculate_values(const std::string& argv) const {
	std::ifstream input_file(argv);
	if (!input_file.is_open()) {
		throw std::runtime_error(RED "Error: Could not open file." + argv + RESET);
	}

	std::string header;
	std::getline(input_file, header);

	std::string line;
	while (std::getline(input_file, line)) {
		size_t delim = line.find('|');
		if (delim == std::string::npos) {
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
			continue;
		}

		std::string date = line.substr(0, delim);
		float value;

		try {
			value = std::stof(line.substr(delim + 1));
		}
		catch (const std::exception& e) {
			std::cerr << RED << argv << ": Invalid number in line: " << line << RESET << std::endl;
			continue;
		}

		if (value < 0) {
			std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
			continue;
		}
		else if (value > 1000) {
			std::cerr << RED << "Error: too large a number." << RESET << std::endl;
			continue;
		}

		// std::map<std::string, float>::iterator itup = _data.upper_bound(date);
		auto itup = _data.upper_bound(date);
		if (itup == _data.begin()) {
			std::cout << date << "=> " << value << " = " << "no value" << std::endl;
		}
		else {
			itup--;
			std::cout << date << "=> " << value << " = " << itup->second * value << std::endl;
		}
	}
	input_file.close();
}
