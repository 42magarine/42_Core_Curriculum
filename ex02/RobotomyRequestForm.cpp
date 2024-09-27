/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:04:52 by mott              #+#    #+#             */
/*   Updated: 2024/09/27 15:20:06 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
	std::cout << YELLOW << "(RobotomyRequestForm) Default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << YELLOW << "(RobotomyRequestForm) Name constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) {
	_target = other._target;
	std::cout << YELLOW << "(RobotomyRequestForm) Copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << YELLOW << "(RobotomyRequestForm) Destructor called" << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		_target = other._target;
		std::cout << YELLOW << "(RobotomyRequestForm) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const {
	(void)bureaucrat;
};
