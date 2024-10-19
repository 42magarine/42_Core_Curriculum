#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);

		~BitcoinExchange();

		BitcoinExchange& operator=(const BitcoinExchange& other);

	private:
};

#endif // BITCOINEXCHANGE_H
