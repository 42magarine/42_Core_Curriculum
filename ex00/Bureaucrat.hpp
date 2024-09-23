#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);

		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

	private:
};

#endif // BUREAUCRAT_H
