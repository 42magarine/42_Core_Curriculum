/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:29:14 by mott              #+#    #+#             */
/*   Updated: 2024/07/16 14:52:23 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address of the string variable: "
			  << &str << std::endl;
	std::cout << "The memory address held by stringPTR: "
			  << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: "
			  << &stringREF << std::endl;

	std::cout << "The value of the string variable: "
			  << str << std::endl;
	std::cout << "The value pointed to by stringPTR: "
			  << *stringPTR << std::endl;
	std::cout << "The Value pointed to by stringREF: "
			  << stringREF << std::endl;

	return 0;
}

// The reference operator (&) is used to create an alias for a variable
// or to obtain the memory address of a variable.

// The dereference operator (*) is used with pointers to access
// or modify the value at the memory address they point to.
