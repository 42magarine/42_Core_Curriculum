/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:18:03 by mott              #+#    #+#             */
/*   Updated: 2024/07/12 18:12:21 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
	public:
		Contact();
		~Contact();
		void			setFirstName();
		void			setLastName();
		void			setNickname();
		void			setPhoneNumber();
		void			setDarkestSecret();
		std::string 	getFirstName();
		std::string 	getLastName();
		std::string 	getNickname();
		std::string 	getPhoneNumber();
		std::string 	getDarkestSecret();

	private:
		std::string		_input;
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickname;
		std::string		_phoneNumber;
		std::string		_darkestSecret;
};

#endif
