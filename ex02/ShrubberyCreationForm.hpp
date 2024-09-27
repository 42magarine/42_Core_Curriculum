#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class ShrubberyCreationForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);

		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	private:
};

#endif // SHRUBBERYCREATIONFORM_H
