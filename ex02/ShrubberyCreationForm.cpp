/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:05:00 by mott              #+#    #+#             */
/*   Updated: 2024/09/27 14:19:45 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
	std::cout << YELLOW << "(ShrubberyCreationForm) Default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {
	std::cout << YELLOW << "(ShrubberyCreationForm) Copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << YELLOW << "(ShrubberyCreationForm) Destructor called" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		std::cout << YELLOW << "(ShrubberyCreationForm) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {

};
