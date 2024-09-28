/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:34:33 by mott              #+#    #+#             */
/*   Updated: 2024/09/28 10:48:53 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << YELLOW << "(Intern) Default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern& other) {
	(void)other;
	std::cout << YELLOW << "(Intern) Copy constructor called" << RESET << std::endl;
}

Intern::~Intern() {
	std::cout << YELLOW << "(Intern) Destructor called" << RESET << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {
		std::cout << YELLOW << "(Intern) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

AForm* Intern::makeForm(const std::string& form, const std::string& target) {
	const std::string form_name[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*form_function[3])(const std::string&) = {
		&Intern::new_ShrubberyCreation,
		&Intern::new_RobotomyRequest,
		&Intern::new_PresidentialPardon
	};

	for (int i = 0; i < 3; i++) {
		if (form_name[i] == form) {
			std::cout << "Intern creates " << form << std::endl;
			return form_function[i](target);
		}
	}
	throw Intern::FormNotFoundException();
};

const char* Intern::FormNotFoundException::what() const noexcept {
	return ">>> Form not found";
}

AForm* Intern::new_ShrubberyCreation(const std::string& target) {
	return new ShrubberyCreationForm(target);
};

AForm* Intern::new_RobotomyRequest(const std::string& target) {
	return new RobotomyRequestForm(target);
};

AForm* Intern::new_PresidentialPardon(const std::string& target) {
	return new PresidentialPardonForm(target);
};
