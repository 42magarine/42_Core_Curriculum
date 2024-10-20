/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:24:47 by mott              #+#    #+#             */
/*   Updated: 2024/10/20 19:04:29 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << RED "Usage: " << argv[0] << " <input_file.txt>" RESET << std::endl;
		return 1;
	}
	try {
		BitcoinExchange btc(argv[1]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}

	// -> class Bitcoin(map, argv[1]);
	// 	-> read argv line by line
	// 	-> error check format
	// 	-> print key/value
