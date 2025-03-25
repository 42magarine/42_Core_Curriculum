/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:23:37 by mott              #+#    #+#             */
/*   Updated: 2024/09/29 13:39:49 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	Data* object = new Data;

	std::cout << "Address: " << object << std::endl
			  << "Id: " << object->getId() << std::endl
			  << "Name: " << object->getName() << std::endl << std::endl;

	uintptr_t serialized_object = Serializer::serialize(object);

	std::cout << "Address (serialized): "
			  << serialized_object << std::endl << std::endl;

	Data* deserialized_object = Serializer::deserialize(serialized_object);

	std::cout << "Address: " << deserialized_object << std::endl
			  << "Id: " << deserialized_object->getId() << std::endl
			  << "Name: " << deserialized_object->getName() << std::endl;

	delete object;
	return 0;
}
