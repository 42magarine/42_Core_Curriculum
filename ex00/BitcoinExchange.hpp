/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:28:59 by mott              #+#    #+#             */
/*   Updated: 2024/10/20 16:01:56 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <map>

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
