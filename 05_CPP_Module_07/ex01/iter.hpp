/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:24:09 by mott              #+#    #+#             */
/*   Updated: 2024/09/29 18:27:48 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T, typename F>
void iter(T* array, size_t length, F func) {
	if (array == nullptr) {
		return;
	}

	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

template<typename T>
void print_array(const T& i) {
	std::cout << i << " ";
}

#endif // ITER_H
