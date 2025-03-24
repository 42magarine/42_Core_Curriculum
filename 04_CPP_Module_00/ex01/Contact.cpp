/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:25:25 by mott              #+#    #+#             */
/*   Updated: 2024/09/24 13:25:37 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(const std::string &input) {
	_first_name = input;
}

void Contact::setLastName(const std::string &input) {
	_last_name = input;
}

void Contact::setNickname(const std::string &input) {
	_nickname = input;
}

void Contact::setPhoneNumber(const std::string &input) {
	_phone_number = input;
}

void Contact::setDarkestSecret(const std::string &input) {
	_darkest_secret = input;
}

std::string Contact::getFirstName() const {
	return _first_name;
}

std::string Contact::getLastName() const {
	return _last_name;
}

std::string Contact::getNickname() const {
	return _nickname;
}

std::string Contact::getPhoneNumber() const {
	return _phone_number;
}

std::string Contact::getDarkestSecret() const {
	return _darkest_secret;
}
