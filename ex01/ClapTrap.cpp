#include "ClapTrap.hpp"
#include <iostream>

// Default constructor
ClapTrap::ClapTrap() {
	std::cout << "Default constructor called" << std::endl;
	// Initialization code
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "Copy constructor called" << std::endl;
	// Copy initialization code
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	// self-assignment check
	if (this != &other) {
		std::cout << "Copy assignment operator called" << std::endl;
		// Copy assignment code
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
	// Cleanup code
}
