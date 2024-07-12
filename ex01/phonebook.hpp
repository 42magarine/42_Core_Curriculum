/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:17:50 by mott              #+#    #+#             */
/*   Updated: 2024/07/12 18:32:24 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void				addContact();
		void				searchContact();

	private:
		void				displayFullContact(int i);
		std::string			truncateString(std::string output);
		int					_index;
		int					_totalContacts;
		static const int	_maxContacts = 8;
		Contact				_contact[_maxContacts];
};

#endif
