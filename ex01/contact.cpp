/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:12:27 by mott              #+#    #+#             */
/*   Updated: 2024/07/10 18:45:38 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

// Constructor
Contact::Contact() {
	std::cout << "Contact created!" << std::endl;
}

// Destructor
Contact::~Contact() {
	std::cout << "Contact destroyed!" << std::endl;
}
