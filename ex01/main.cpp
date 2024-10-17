/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:49:41 by mott              #+#    #+#             */
/*   Updated: 2024/10/18 00:12:58 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// int main() {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return 0;
// }

// int main() {
// 	Span sp(1);

// 	sp.addNumber(42);

// 	try {
// 		std::cout << sp.shortestSpan() << std::endl;
// 		std::cout << sp.longestSpan() << std::endl;
// 	}
// 	catch (std::exception& e) {
// 		std::cerr << RED << e.what() << RESET << std::endl;
// 	}
// 	return 0;
// }

// int main() {
// 	Span sp(2);

// 	try {
// 		sp.addNumber(40);
// 		sp.addNumber(41);
// 		sp.addNumber(42);
// 	}
// 	catch (std::exception& e) {
// 		std::cerr << RED << e.what() << RESET << std::endl;
// 	}
// 	return 0;
// }

int main() {
	Span sp = Span(7);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::vector<int> values = {10, 45};

	sp.addNumber(values);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
