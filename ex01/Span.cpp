/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:49:46 by mott              #+#    #+#             */
/*   Updated: 2024/10/18 00:20:54 by mott             ###   ########.fr       */
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
		throw std::length_error("Span is already full");
	}
	_vector.push_back(value);
}

void Span::addNumber(std::vector<int> values) {
	if (_vector.size() + values.size() > _size) {
		throw std::length_error("Span is already full");
	}
	_vector.insert(_vector.end(), values.begin(), values.end());
}

int Span::shortestSpan() {
	if (_vector.size() < 2) {
		throw std::length_error("Not enough numbers in span");
	}

	std::vector<int> sorted_vector(_vector);
	std::sort(sorted_vector.begin(), sorted_vector.end());

	int min_span = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted_vector.size() - 1; i++) {
		int span = sorted_vector[i + 1] - sorted_vector[i];
		min_span = std::min(min_span, span);
	}
	return min_span;
}

int Span::longestSpan() {
	if (_vector.size() < 2) {
		throw std::length_error("Not enough numbers in span");
	}

	return *std::max_element(_vector.begin(), _vector.end()) - *std::min_element(_vector.begin(), _vector.end());
}
