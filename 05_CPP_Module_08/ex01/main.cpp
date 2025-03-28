/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:49:41 by mott              #+#    #+#             */
/*   Updated: 2024/10/19 17:27:45 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main() {
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}

// int main() {
// 	Span sp(1);

// 	sp.addNumber(42);

// 	try {
// 		std::cout << sp.shortestSpan() << std::endl;
// 		std::cout << sp.longestSpan() << std::endl;
// 	}
// 	catch (std::exception& e) {
// 		std::cerr << e.what() << std::endl;
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
// 		std::cerr << e.what() << std::endl;
// 	}
// 	return 0;
// }

// int main() {
// 	Span sp = Span(7);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	try {
// 		std::vector<int> values = {10, 45, 111};
// 		sp.addNumber(values);
// 	}
// 	catch (std::exception& e) {
// 		std::cerr << e.what() << std::endl;
// 	}

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return 0;
// }

// int main() {
// 	std::srand(std::time(nullptr));

// 	std::vector<int> random_numbers;
// 	unsigned int size = 10000;

// 	for (unsigned int i = 0; i < size; i++) {
// 		random_numbers.push_back(std::rand() % 100000);
// 	}

// 	Span sp(size);
// 	sp.addNumber(random_numbers);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return 0;
// }
