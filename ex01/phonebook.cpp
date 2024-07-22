/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:12:08 by mott              #+#    #+#             */
/*   Updated: 2024/07/22 15:40:34 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _totalContacts(0), _index(0) {}

void PhoneBook::addContact() {
	Contact contact;
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);

	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
		std::cout << "A contact cant't have empty fields!" << std::endl;
		return;
	}

	_contact[_index].setFirstName(firstName);
	_contact[_index].setLastName(lastName);
	_contact[_index].setNickname(nickname);
	_contact[_index].setPhoneNumber(phoneNumber);
	_contact[_index].setDarkestSecret(darkestSecret);

	_index = (_index + 1) % _maxContacts;
	if (_totalContacts < _maxContacts) {
		_totalContacts++;
	}
}

void PhoneBook::searchContact() const {
	if (_totalContacts == 0) {
		std::cout << "No contacts!" << std::endl;
		return;
	}

	std::cout << std::setw(10) << "index" << "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nickname" << std::endl;

	for (int i = 0; i < _totalContacts; ++i) {
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << cutString(_contact[i].getFirstName()) << "|"
		 		  << std::setw(10) << cutString(_contact[i].getLastName()) << "|"
				  << std::setw(10) << cutString(_contact[i].getNickname()) << std::endl;
	}

	int index;
	std::cout << "Enter an index: ";
	if (!(std::cin >> index)) {
		std::cout << "Invalid index!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	std::cin.ignore();
	if (index < 0 || index >= _totalContacts) {
		std::cout << "Invalid index." << std::endl;
		return;
	}
	displayContact(index);
}

void PhoneBook::displayContact(int index) const {
		std::cout << "First Name: " << _contact[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << _contact[index].getLastName() << std::endl;
		std::cout << "Nickname: " << _contact[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << _contact[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << _contact[index].getDarkestSecret() << std::endl;
}

std::string PhoneBook::cutString(std::string output) const {
	if (output.length() > 10) {
		return output.substr(0, 9) + ".";
	}
	return output;
}
