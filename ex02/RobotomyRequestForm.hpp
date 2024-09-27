#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class RobotomyRequestForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);

		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	private:
};

#endif // ROBOTOMYREQUESTFORM_H
