/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:16:02 by mott              #+#    #+#             */
/*   Updated: 2024/09/30 12:32:53 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _grade_to_sign(150), _grade_to_execute(150) {
	std::cout << YELLOW << "(From) Default constructor called" << RESET << std::endl;
}

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
	if (_grade_to_sign < 1 || _grade_to_execute < 1) {
		throw Form::GradeTooHighException();
	}
	if (_grade_to_sign > 150 || _grade_to_execute > 150) {
		throw Form::GradeTooLowException();
	}
	std::cout << YELLOW << "(Form) Name constructor called" << RESET << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute) {
	std::cout << YELLOW << "(Form) Copy constructor called" << RESET << std::endl;
}

Form::~Form() {
	std::cout << YELLOW << "(Form) Destructor called" << RESET << std::endl;
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		_signed = other._signed;
		std::cout << YELLOW << "(Form) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

const std::string& Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _grade_to_sign;
}

int Form::getGradeToExecute() const {
	return _grade_to_execute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _grade_to_sign) {
		throw Form::GradeTooLowException();
	}
	_signed = true;
}

const char* Form::GradeTooHighException::what() const noexcept {
	return ">>> Form grade is too high";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return ">>> Form grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Name: " << form.getName() << std::endl
	<< "Signed: " << (form.getSigned() ? "true" : "false") << std::endl
	<< "Grade to sign: " << form.getGradeToSign() << std::endl
	<< "Grade to execute: " << form.getGradeToExecute();
	return os;
}
