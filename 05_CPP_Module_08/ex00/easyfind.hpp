/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:49:34 by mott              #+#    #+#             */
/*   Updated: 2024/10/17 19:04:51 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <algorithm>		// std::find
#include <stdexcept>		// std::out_of_range

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw std::out_of_range("Value not found in container");
	}
	return it;
}

#endif // EASYFIND_H
