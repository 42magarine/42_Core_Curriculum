#ifndef RPN_H
#define RPN_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class RPN {
	public:
		RPN();
		RPN(const RPN& other);

		~RPN();

		RPN& operator=(const RPN& other);

	private:
};

#endif // RPN_H
