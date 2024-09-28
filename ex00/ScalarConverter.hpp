/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:14:44 by mott              #+#    #+#             */
/*   Updated: 2024/09/28 15:14:45 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);

		~ScalarConverter();

		ScalarConverter& operator=(const ScalarConverter& other);

	private:
};

#endif // SCALARCONVERTER_H
