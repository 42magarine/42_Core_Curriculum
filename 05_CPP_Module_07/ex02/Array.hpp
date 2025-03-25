/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:08:56 by mott              #+#    #+#             */
/*   Updated: 2024/09/30 13:34:48 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <stdexcept>		// std::out_of_range

template <typename T>
class Array {
	public:
		Array() : _array(nullptr), _size(0) {}

		Array(unsigned int n) : _array(new T[n]()), _size(n) {}

		Array(const Array& other) : _array(new T[other._size]), _size(other._size) {
			for (unsigned int i = 0; i < _size; i++) {
				_array[i] = other._array[i];
			}
		}

		~Array() {
			delete[] _array;
		}

		Array& operator=(const Array& other) {
			if (this != &other) {
				delete[] _array;

				_size = other._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++) {
					_array[i] = other._array[i];
				}
			}
			return *this;
		}

		T& operator[](unsigned int index) {
			if (index >= _size) {
				throw std::out_of_range("Index is out of bounds");
			}
			return _array[index];
		}

		const T& operator[](unsigned int index) const {
			if (index >= _size) {
				throw std::out_of_range("Index is out of bounds");
			}
			return _array[index];
		}

		unsigned int size() const {
			return _size;
		}

	private:
		T* _array;
		unsigned int _size;
};

#endif // ARRAY_H
