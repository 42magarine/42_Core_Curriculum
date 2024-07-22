/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:17:50 by mott              #+#    #+#             */
/*   Updated: 2024/07/22 15:12:35 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();

		void addContact();
		void searchContact() const;
		void displayContact(int index) const;

	private:
		std::string cutString(std::string output) const;

		static const int _maxContacts = 8;
		Contact _contact[_maxContacts];
		int _totalContacts;
		int _index;
};

#endif
