/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:08:56 by mott              #+#    #+#             */
/*   Updated: 2024/09/30 12:39:44 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>		// std::out_of_range

class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);

		~Array();

		Array& operator=(const Array& other);
		int& operator[](unsigned int index);
		const int& operator[](unsigned int index) const;

		unsigned int size() const;

	private:
		int* _array;
		unsigned int _size;
};

#endif // ARRAY_H
