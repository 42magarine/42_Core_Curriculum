/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:12:08 by mott              #+#    #+#             */
/*   Updated: 2024/07/12 18:40:47 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0), _totalContacts(0) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact() {
	_contact[_index].setFirstName();
	_contact[_index].setLastName();
	_contact[_index].setNickname();
	_contact[_index].setPhoneNumber();
	_contact[_index].setDarkestSecret();

	_index = (_index + 1) % _maxContacts;
	if (_totalContacts < _maxContacts) {
		_totalContacts++;
	}
}

void	PhoneBook::searchContact() {
	std::string	input;
	int			i;

	if (_totalContacts == 0) {
		std::cout << "No contacts." << std::endl;
		return;
	}

	std::cout << std::string(43, '-') << std::endl;
	std::cout << std::setw(10) << "index" << "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nickname" << std::endl;

	for (int i = 0; i < _totalContacts; ++i) {
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << truncateString(_contact[i].getFirstName()) << "|"
		 		  << std::setw(10) << truncateString(_contact[i].getLastName()) << "|"
				  << std::setw(10) << truncateString(_contact[i].getNickname()) << std::endl;
	}

	std::cout << "Enter an index: ";
	std::getline(std::cin, input);
	try {
		i = std::stoi(input);
	}
	catch (std::exception &e) {
		std::cout << "Invalid index." << std::endl;
		return;
	}

	if (i < 0 || i >= _totalContacts) {
		std::cout << "Invalid index." << std::endl;
	}
	else {
		displayFullContact(i);
	}
}

void	PhoneBook::displayFullContact(int i) {
		std::cout << std::string(43, '-') << std::endl;
		std::cout << "First Name: " << _contact[i].getFirstName() << std::endl;
		std::cout << "Last Name: " << _contact[i].getLastName() << std::endl;
		std::cout << "Nickname: " << _contact[i].getNickname() << std::endl;
		std::cout << "Phone Number: " << _contact[i].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << _contact[i].getDarkestSecret() << std::endl;
}

std::string	PhoneBook::truncateString(std::string output) {
	if (output.length() > 10) {
		return output.substr(0, 9) + ".";
	}
	return output;
}
