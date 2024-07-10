/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:12:08 by mott              #+#    #+#             */
/*   Updated: 2024/07/10 19:02:03 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook() {
	std::cout << "PhoneBook created!" << std::endl;
}

// Destructor
PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook destroyed!" << std::endl;
}
