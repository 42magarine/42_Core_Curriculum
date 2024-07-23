#!/bin/bash

# Function to display usage
usage() {
	echo "Usage: $0 <Directory> <ClassName>"
	exit 1
}

# Check if the output directory and class name are provided
if [ -z "$1" ] || [ -z "$2" ]; then
	usage
fi

# Output directory and class name
OUTPUT_DIR=$1
CLASS_NAME=$2

# Create the output directory if it doesn't exist
mkdir -p "$OUTPUT_DIR"

# Convert class name to uppercase for include guard
CLASS_NAME_UPPER=$(echo "$CLASS_NAME" | tr '[:lower:]' '[:upper:]')

# Header file name
HPP_FILE="${OUTPUT_DIR}/${CLASS_NAME}.hpp"

# Source file name
CPP_FILE="${OUTPUT_DIR}/${CLASS_NAME}.cpp"

# Create the header file
cat << EOF > $HPP_FILE
#ifndef ${CLASS_NAME_UPPER}_H
#define ${CLASS_NAME_UPPER}_H

class $CLASS_NAME {
	public:
		// Default constructor
		$CLASS_NAME();

		// Copy constructor
		$CLASS_NAME(const $CLASS_NAME &other);

		// Copy assignment operator
		$CLASS_NAME& operator=(const $CLASS_NAME &other);

		// Destructor
		~$CLASS_NAME();

	private:
		// Class members
};

#endif // ${CLASS_NAME_UPPER}_H
EOF

# Create the source file
cat << EOF > $CPP_FILE
#include "${CLASS_NAME}.hpp"
#include <iostream>

// Default constructor
$CLASS_NAME::$CLASS_NAME() {
	std::cout << "Default constructor called" << std::endl;
	// Initialization code
}

// Copy constructor
$CLASS_NAME::$CLASS_NAME(const $CLASS_NAME &other) {
	std::cout << "Copy constructor called" << std::endl;
	// Copy initialization code
}

// Copy assignment operator
$CLASS_NAME& $CLASS_NAME::operator=(const $CLASS_NAME &other) {
	// self-assignment check
	if (this != &other) {
		std::cout << "Copy assignment operator called" << std::endl;
		// Copy assignment code
	}
	return *this;
}

// Destructor
$CLASS_NAME::~$CLASS_NAME() {
	std::cout << "Destructor called" << std::endl;
	// Cleanup code
}
EOF

echo "Created $HPP_FILE and $CPP_FILE with a standard class in orthodox canonical form."
