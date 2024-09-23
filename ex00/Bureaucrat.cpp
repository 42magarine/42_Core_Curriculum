/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:39:24 by mott              #+#    #+#             */
/*   Updated: 2024/09/23 17:52:49 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade) {
	if (_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << YELLOW << "Name constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
		std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

std::string Bureaucrat::getName() const {
	return _name;
}

unsigned int Bureaucrat::getGrade() const {
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

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return ">>> Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return ">>> Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
