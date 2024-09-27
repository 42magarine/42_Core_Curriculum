#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}
