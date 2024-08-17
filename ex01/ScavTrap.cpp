#include "ScavTrap.hpp"
#include <iostream>

// Default constructor
ScavTrap::ScavTrap() {
	std::cout << "Default constructor called" << std::endl;
	// Initialization code
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) {
	std::cout << "Copy constructor called" << std::endl;
	// Copy initialization code
}

// Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	// self-assignment check
	if (this != &other) {
		std::cout << "Copy assignment operator called" << std::endl;
		// Copy assignment code
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "Destructor called" << std::endl;
	// Cleanup code
}
