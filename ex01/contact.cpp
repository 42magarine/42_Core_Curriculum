/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:44:09 by mott              #+#    #+#             */
/*   Updated: 2024/07/12 18:39:04 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::setFirstName() {
	do {
		std::cout << "Enter first name: ";
		std::getline(std::cin, _input);
	} while (_input.empty());
	_firstName = _input;
}

void	Contact::setLastName() {
	do {
		std::cout << "Enter last name: ";
		std::getline(std::cin, _input);
	} while (_input.empty());
	_lastName = _input;
}

void	Contact::setNickname() {
	do {
		std::cout << "Enter nickname: ";
		std::getline(std::cin, _input);
	} while (_input.empty());
	_nickname = _input;
}

void	Contact::setPhoneNumber() {
	do {
		std::cout << "Enter phone number: ";
		std::getline(std::cin, _input);
	} while (_input.empty());
	_phoneNumber = _input;
}

void	Contact::setDarkestSecret() {
	do {
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, _input);
	} while (_input.empty());
	_darkestSecret = _input;
}

std::string Contact::getFirstName() {
	return _firstName;
}

std::string Contact::getLastName() {
	return _lastName;
}

std::string Contact::getNickname() {
	return _nickname;
}

std::string Contact::getPhoneNumber() {
	return _phoneNumber;
}

std::string Contact::getDarkestSecret() {
	return _darkestSecret;
}
