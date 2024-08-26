/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:17:50 by mott              #+#    #+#             */
/*   Updated: 2024/08/26 14:51:20 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook {
	public:
		PhoneBook();

		void addContact();
		void searchContact() const;

	private:
		std::string cutString(std::string output) const;
		void displayContact(int index) const;

		Contact _contacts[8];
		int _contact_counter;
		int _index;
};

#endif
