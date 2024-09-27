#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}
