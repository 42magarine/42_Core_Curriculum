/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:16:02 by mott              #+#    #+#             */
/*   Updated: 2024/09/23 19:09:36 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _grade_to_sign(150), _grade_to_execute(150) {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
	std::cout << YELLOW << "Name constructor called" << RESET << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

Form::~Form() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		_signed = other._signed;
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

const std::string& Form::getName() const {
	return _name;
};

bool Form::getSigned() const {
	return _signed;
};

int Form::getGradeToSign() const {
	return _grade_to_sign;
};

int Form::getGradeToExecute() const {
	return _grade_to_execute;
};

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Name: " << form.getName() << std::endl
	<< "Signed: " << (form.getSigned() ? "true" : "false") << std::endl
	<< "Grade to sign: " << form.getGradeToSign() << std::endl
	<< "Grade to execute: " << form.getGradeToExecute();
	return os;
}
