/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:12:08 by mott              #+#    #+#             */
/*   Updated: 2024/08/28 16:48:58 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _contact_counter(0), _index(0) {}

void PhoneBook::addContact() {
	std::string first_name, last_name, nickname, phone_number, darkest_secret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	if (std::cin.eof()) {
		exit(0);
	}
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	if (std::cin.eof()) {
		exit(0);
	}
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	if (std::cin.eof()) {
		exit(0);
	}
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone_number);
	if (std::cin.eof()) {
		exit(0);
	}
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkest_secret);
	if (std::cin.eof()) {
		exit(0);
	}

	if (first_name.empty() || last_name.empty() || nickname.empty() || phone_number.empty() || darkest_secret.empty()) {
		std::cout << "A contact cannot have empty fields." << std::endl;
		return;
	}

	_contacts[_index].setFirstName(first_name);
	_contacts[_index].setLastName(last_name);
	_contacts[_index].setNickname(nickname);
	_contacts[_index].setPhoneNumber(phone_number);
	_contacts[_index].setDarkestSecret(darkest_secret);

	_index = (_index + 1) % 8;

	if (_contact_counter < 8) {
		_contact_counter++;
	}
}

void PhoneBook::searchContact() const {
	if (_contact_counter == 0) {
		std::cout << "The phonebook is empty." << std::endl;
		return;
	}

	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "first name";
	std::cout << "|" << std::setw(10) << "last name";
	std::cout << "|" << std::setw(10) << "nickname";
	std::cout << "|" << std::endl;

	for (int i = 0; i < _contact_counter; i++) {
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << cutString(_contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << cutString(_contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << cutString(_contacts[i].getNickname());
		std::cout << "|" << std::endl;
	}

	int index;
	std::cout << "Enter an index of an entry to display: ";
	std::cin >> index;
	if (std::cin.eof()) {
		exit(0);
	}
	else if (std::cin.fail() || index < 0 || index >= _contact_counter) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index." << std::endl;
	}
	else {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		displayContact(index);
	}
}

std::string PhoneBook::cutString(std::string output) const {
	if (output.length() > 10) {
		return output.substr(0, 9) + ".";
	}
	return output;
}

void PhoneBook::displayContact(int index) const {
		std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
		std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
}
