/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:04:49 by mott              #+#    #+#             */
/*   Updated: 2024/09/27 18:50:18 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("default") {
	std::cout << YELLOW << "(PresidentialPardonForm) Default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {
	std::cout << YELLOW << "(PresidentialPardonForm) Name constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {
	std::cout << YELLOW << "(PresidentialPardonForm) Copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << YELLOW << "(PresidentialPardonForm) Destructor called" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
		std::cout << YELLOW << "(PresidentialPardonForm) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

void PresidentialPardonForm::execute_form() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
};
