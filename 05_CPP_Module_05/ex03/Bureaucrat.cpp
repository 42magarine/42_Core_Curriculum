/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:39:24 by mott              #+#    #+#             */
/*   Updated: 2024/09/30 12:31:43 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cout << YELLOW << "(Bureaucrat) Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << YELLOW << "(Bureaucrat) Name constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << YELLOW << "(Bureaucrat) Copy constructor called" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << YELLOW << "(Bureaucrat) Destructor called" << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
		std::cout << YELLOW << "(Bureaucrat) Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade <= 1) {
		throw Bureaucrat::GradeTooHighException();
	}
		_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
}

void Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return ">>> Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return ">>> Bureaucrat grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
