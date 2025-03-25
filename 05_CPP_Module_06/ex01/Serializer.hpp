/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:24:53 by mott              #+#    #+#             */
/*   Updated: 2024/09/29 12:56:13 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "Data.hpp"
#include <iostream>
#include <cstdint>		// uintptr_t

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Serializer {
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer& other);

		~Serializer();

		Serializer& operator=(const Serializer& other);
};

#endif // SERIALIZER_H
