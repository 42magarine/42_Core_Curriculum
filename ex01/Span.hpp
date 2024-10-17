/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:49:49 by mott              #+#    #+#             */
/*   Updated: 2024/10/17 23:57:45 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <cstddef>

#define RESET "\033[0m"
#define RED   "\033[31m"

class Span {
	public:
		Span() = delete;
		Span(unsigned int n);
		Span(const Span& other);

		~Span();

		Span& operator=(const Span& other);

		void addNumber(int value);
		void addNumber(std::vector<int> values);
		int shortestSpan();
		int longestSpan();

	private:
		unsigned int _size;
		std::vector<int> _vector;
};

#endif // SPAN_H
