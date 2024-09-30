/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:16:02 by mott              #+#    #+#             */
/*   Updated: 2024/09/30 12:31:37 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _grade_to_sign(150), _grade_to_execute(150) {
	std::cout << YELLOW << "(From) Default constructor called" << RESET << std::endl;
}

AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
	if (_grade_to_sign < 1 || _grade_to_execute < 1) {
		throw AForm::GradeTooHighException();
	}
	if (_grade_to_sign > 150 || _grade_to_execute > 150) {
		throw AForm::GradeTooLowException();
	}
	std::cout << YELLOW << "(AForm) Name constructor called" << RESET << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute) {
	std::cout << YELLOW << "(AForm) Copy constructor called" << RESET << std::endl;
}

AForm::~AForm() {
	std::cout << YELLOW << "(AForm) Destructor called" << RESET << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		_signed = other._signed;
		std::cout << YELLOW << "(AForm) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

const std::string& AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGradeToSign() const {
	return _grade_to_sign;
}

int AForm::getGradeToExecute() const {
	return _grade_to_execute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _grade_to_sign) {
		throw AForm::GradeTooLowException();
	}
	_signed = true;
}

void AForm::execute(const Bureaucrat& bureaucrat) const {
	if (!_signed) {
		throw FormNotSignedException();
	}
	if (bureaucrat.getGrade() > _grade_to_execute) {
		throw GradeTooLowException();
	}
	execute_form();
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return ">>> Form grade is too high";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return ">>> Form grade is too low";
}

const char* AForm::FormNotSignedException::what() const noexcept {
	return ">>> Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& aform) {
	os << "Name: " << aform.getName() << std::endl
	<< "Signed: " << (aform.getSigned() ? "true" : "false") << std::endl
	<< "Grade to sign: " << aform.getGradeToSign() << std::endl
	<< "Grade to execute: " << aform.getGradeToExecute();
	return os;
}
