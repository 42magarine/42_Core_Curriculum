/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:30:27 by mott              #+#    #+#             */
/*   Updated: 2024/09/23 17:50:03 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	Bureaucrat a;
	Bureaucrat b("b", 1);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	try {
		a.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		b.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	try {
		Bureaucrat c("c", 0);
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat d("d", 151);
	}
	catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
