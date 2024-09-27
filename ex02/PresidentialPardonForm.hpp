#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class PresidentialPardonForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);

		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	private:
};

#endif // PRESIDENTIALPARDONFORM_H
