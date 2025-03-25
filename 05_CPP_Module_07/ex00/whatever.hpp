/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:50:24 by mott              #+#    #+#             */
/*   Updated: 2024/09/29 17:12:36 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>
#include <string>

template <typename T>
void swap(T& a, T& b) {
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(const T& a, const T& b) {
	return (a < b) ? a : b;
}


template<typename T>
T max(const T& a, const T& b) {
	return a > b ? a : b;
}

#endif // WHATEVER_H
