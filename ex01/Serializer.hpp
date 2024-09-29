/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:24:53 by mott              #+#    #+#             */
/*   Updated: 2024/09/29 12:25:01 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Serializer {
	public:

	private:
		Serializer();
		Serializer(const Serializer& other);

		~Serializer();

		Serializer& operator=(const Serializer& other);
};

#endif // SERIALIZER_H
