/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:11:47 by mott              #+#    #+#             */
/*   Updated: 2024/07/10 17:31:30 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
	std::string	command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::cin >> command;
		if (command == "ADD") {
			std::cout << "add" << std::endl;
		}
		else if (command == "SEARCH") {
			std::cout << "search" << std::endl;
		}
		else if (command == "EXIT") {
			break;
		}
		else {
			continue;
		}
	}
	return 0;
}
