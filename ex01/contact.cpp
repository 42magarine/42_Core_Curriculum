/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:44:09 by mott              #+#    #+#             */
/*   Updated: 2024/07/22 14:17:23 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

void Contact::setFirstName(const std::string &input) {
	_firstName = input;
}

void Contact::setLastName(const std::string &input) {
	_lastName = input;
}

void Contact::setNickname(const std::string &input) {
	_nickname = input;
}

void Contact::setPhoneNumber(const std::string &input) {
	_phoneNumber = input;
}

void Contact::setDarkestSecret(const std::string &input) {
	_darkestSecret = input;
}

std::string Contact::getFirstName() const {
	return _firstName;
}

std::string Contact::getLastName() const {
	return _lastName;
}

std::string Contact::getNickname() const {
	return _nickname;
}

std::string Contact::getPhoneNumber() const {
	return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return _darkestSecret;
}
