#include "Intern.hpp"

Intern::Intern() {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

Intern::~Intern() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}
