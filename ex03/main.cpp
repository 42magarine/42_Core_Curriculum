/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:30:27 by mott              #+#    #+#             */
/*   Updated: 2024/09/28 11:02:46 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Intern someRandomIntern;
	AForm* rrf[4] = {nullptr, nullptr, nullptr, nullptr};

	try {
		rrf[0] = someRandomIntern.makeForm("shrubbery creation", "Bender");
		rrf[1] = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf[2] = someRandomIntern.makeForm("presidential pardon", "Bender");
		rrf[3] = someRandomIntern.makeForm("strange random name", "Bender");
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	for (int i = 0; i < 4; i++) {
		if (rrf[i]) {
			delete rrf[i];
		}
	}
	
	return 0;
}
