/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:28:56 by mott              #+#    #+#             */
/*   Updated: 2024/10/30 14:17:57 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream data_file(DATA_FILE);
	if (!data_file.is_open()) {
		throw std::runtime_error(RED "Error: Could not open file." RESET);
	}

	std::string header;
	std::getline(data_file, header);

	std::string line;
	while (std::getline(data_file, line)) {
		size_t delim = line.find(',');
		if (delim == std::string::npos) {
			std::cerr << RED << "Error: Invalid format in line: " << line << RESET << std::endl;
			continue;
		}

		std::string date = line.substr(0, delim);
		float value;

		try {
			value = std::stof(line.substr(delim + 1));
		}
		catch (const std::exception& e) {
			std::cerr << RED << "Error: Invalid number in line: " << line << RESET << std::endl;
			continue;
		}

		if (value < 0) {
			std::cerr << RED << "Error: Invalid value in line: " << line << RESET << std::endl;
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
		throw std::runtime_error(RED "Error: Could not open file." RESET);
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
		if (!isvalid_date(date)) {
			std::cerr << RED << "Error: Invalid date => " << date << RESET << std::endl;
			continue;
		}

		float value;
		try {
			value = std::stof(line.substr(delim + 1));
		}
		catch (const std::exception& e) {
			std::cerr << RED << "Error: Invalid number in line: " << line << RESET << std::endl;
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

bool BitcoinExchange::isvalid_date(const std::string& date) const {
	int year, month, day;

	if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
		return false;
	}

	if (year < 1900 || year > 2100 || month < 1 || month > 12) {
		return false;
	}

	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		days_in_month[1] = 29;
	}

	if (day < 1 || day > days_in_month[month - 1]) {
		return false;
	}

	return true;
}
