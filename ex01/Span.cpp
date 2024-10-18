/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:49:46 by mott              #+#    #+#             */
/*   Updated: 2024/10/18 18:23:05 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _size(n) {
}

Span::Span(const Span& other) : _size(other._size), _vector(other._vector) {
}

Span::~Span() {
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_size = other._size;
		_vector = other._vector;
	}
	return *this;
}

void Span::addNumber(int value) {
	if (_vector.size() >= _size) {
		throw std::length_error(RED "Span is already full" RESET);
	}
	_vector.push_back(value);
}

void Span::addNumber(std::vector<int> values) {
	if (_vector.size() + values.size() > _size) {
		throw std::length_error(RED "Span is already full" RESET);
	}
	_vector.insert(_vector.end(), values.begin(), values.end());
}

int Span::shortestSpan() const {
	if (_vector.size() < 2) {
		throw std::length_error(RED "Not enough numbers in span" RESET);
	}

	std::vector<int> sorted_vector(_vector);
	std::sort(sorted_vector.begin(), sorted_vector.end());

	int min_span = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted_vector.size() - 1; i++) {
		int span = std::abs(sorted_vector[i + 1] - sorted_vector[i]);
		min_span = std::min(min_span, span);
	}
	return min_span;
}

int Span::longestSpan() const {
	if (_vector.size() < 2) {
		throw std::length_error(RED "Not enough numbers in span" RESET);
	}
	return *std::max_element(_vector.begin(), _vector.end()) - *std::min_element(_vector.begin(), _vector.end());
}
