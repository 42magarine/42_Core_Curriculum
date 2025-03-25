/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:30:27 by mott              #+#    #+#             */
/*   Updated: 2024/09/27 19:12:21 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::srand(std::time(nullptr));

	Bureaucrat bob("Bob", 5);
	// Bureaucrat bob("Bob", 25);
	// Bureaucrat bob("Bob", 45);
	// Bureaucrat bob("Bob", 72);
	// Bureaucrat bob("Bob", 137);
	// Bureaucrat bob("Bob", 145);
	std::cout << bob << std::endl;

	AForm *p1 = new ShrubberyCreationForm("home");
	AForm *p2 = new RobotomyRequestForm("home-two");
	AForm *p3 = new PresidentialPardonForm("home-three");

	// std::cout << *p1 << std::endl << std::endl;
	// std::cout << *p2 << std::endl << std::endl;
	// std::cout << *p3 << std::endl << std::endl;

	// bob.executeForm(*p1);
	// bob.executeForm(*p2);
	// bob.executeForm(*p3);
	// std::cout << std::endl;

	bob.signForm(*p1);
	bob.signForm(*p2);
	bob.signForm(*p3);
	std::cout << std::endl;

	bob.executeForm(*p1);
	bob.executeForm(*p2);
	bob.executeForm(*p2);
	bob.executeForm(*p2);
	bob.executeForm(*p3);
	std::cout << std::endl;

	// std::cout << *p1 << std::endl << std::endl;
	// std::cout << *p2 << std::endl << std::endl;
	// std::cout << *p3 << std::endl << std::endl;

	delete p1;
	delete p2;
	delete p3;

	return 0;
}
