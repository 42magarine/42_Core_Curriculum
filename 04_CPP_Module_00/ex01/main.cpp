/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:11:47 by mott              #+#    #+#             */
/*   Updated: 2024/08/27 13:40:19 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
	PhoneBook phonebook;
	std::string command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof()) {
			break;
		}

		if (command == "ADD") {
			phonebook.addContact();
		}
		else if (command == "SEARCH") {
			phonebook.searchContact();
		}
		else if (command == "EXIT") {
			break;
		}
		else {
			std::cout << "Invalid command!" << std::endl;
		}
	}
	return 0;
}
