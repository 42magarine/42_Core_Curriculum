#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}
