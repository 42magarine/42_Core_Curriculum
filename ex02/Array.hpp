/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:08:56 by mott              #+#    #+#             */
/*   Updated: 2024/09/29 20:43:08 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);

		~Array();

		Array& operator=(const Array& other);
		int& operator[](unsigned int index);

		unsigned int size() const;

	private:
		int* _array;
		unsigned int _size;
};

#endif // ARRAY_H
