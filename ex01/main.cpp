/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:11:47 by mott              #+#    #+#             */
/*   Updated: 2024/07/10 20:16:36 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void) {
	std::string	command;
	PhoneBook	phone_book;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD") {
			std::cout << "add" << std::endl;
		}
		else if (command == "SEARCH") {
			std::cout << "search" << std::endl;
		}
		else if (command == "EXIT") {
			break;
		}
	}
	return 0;
}
