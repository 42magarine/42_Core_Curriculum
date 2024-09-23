#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}
