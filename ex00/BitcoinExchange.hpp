/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:28:59 by mott              #+#    #+#             */
/*   Updated: 2024/10/20 18:51:31 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <stdexcept>

#define RESET		"\033[0m"
#define RED			"\033[31m"
#define YELLOW		"\033[33m"
#define DATA_FILE	"data.csv"

class BitcoinExchange {
	public:
		BitcoinExchange() = delete;
		BitcoinExchange(const std::string& input_file);
		BitcoinExchange(const BitcoinExchange& other);

		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange& other);

	private:
		void print_map() const;

		std::map<std::string, float> _data;
};

#endif // BITCOINEXCHANGE_H
