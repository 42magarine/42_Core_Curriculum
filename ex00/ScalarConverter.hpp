/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:14:44 by mott              #+#    #+#             */
/*   Updated: 2024/09/28 21:00:32 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <string>
#include <cstdlib>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class ScalarConverter {
	public:
		static void convert(const std::string& input);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);

		~ScalarConverter();

		ScalarConverter& operator=(const ScalarConverter& other);

		static void print(char input);
		static void print(int input);
		static void print(float input);
		static void print(double input);
};

#endif // SCALARCONVERTER_H
