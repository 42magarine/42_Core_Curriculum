#ifndef INTERN_H
#define INTERN_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Intern {
	public:
		Intern();
		Intern(const Intern& other);

		~Intern();

		Intern& operator=(const Intern& other);

	private:
};

#endif // INTERN_H
