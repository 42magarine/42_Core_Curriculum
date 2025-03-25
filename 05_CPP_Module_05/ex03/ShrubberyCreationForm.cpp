/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:05:00 by mott              #+#    #+#             */
/*   Updated: 2024/09/30 12:32:01 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("default") {
	std::cout << YELLOW << "(ShrubberyCreationForm) Default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {
	std::cout << YELLOW << "(ShrubberyCreationForm) Name constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {
	std::cout << YELLOW << "(ShrubberyCreationForm) Copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << YELLOW << "(ShrubberyCreationForm) Destructor called" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
		std::cout << YELLOW << "(ShrubberyCreationForm) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

void ShrubberyCreationForm::execute_form() const {
	std::ofstream file(_target + "_shrubbery");
	if (!file.is_open()) {
		std::cerr << "Could not create " << _target << "_shrubbery" << std::endl;
		return;
	}
	file << "        🌲\n"
		 << "       🌲🌲\n"
		 << "      🌲🌲🌲\n"
		 << "     🌲🌲🌲🌲\n"
		 << "    🌲🌲🌲🌲🌲\n"
		 << "   🌲🌲🌲🌲🌲🌲\n"
		 << "      ||||\n"
		 << "      ||||\n";
	file.close();
}
