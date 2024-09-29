/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:09:42 by mott              #+#    #+#             */
/*   Updated: 2024/09/29 21:29:03 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

Array::Array() : _array(nullptr), _size(0) {};

Array::Array(unsigned int n) : _array(new int[n]()), _size(n) {};

Array::Array(const Array& other) : _array(new int[other._size]), _size(other._size) {
	for (unsigned int i = 0; i < _size; i++) {
		_array[i] = other._array[i];
	}
};

Array::~Array() {
	delete[] _array;
};

Array& Array::operator=(const Array& other) {
	if (this != &other) {
		delete[] _array;
		_size = other._size;
		_array = new int[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = other._array[i];
		}
	}
	return *this;
};

int& Array::operator[](unsigned int index) {
	return _array[index];
};

unsigned int Array::size() const {
	return _size;
};
