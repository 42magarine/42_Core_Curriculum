/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:15:56 by mott              #+#    #+#             */
/*   Updated: 2024/09/24 19:24:50 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Form {
	public:
		Form();
		Form(const std::string& name, int grade_to_sign, int grade_to_execute);
		Form(const Form& other);

		~Form();

		Form& operator=(const Form& other);

		const std::string& getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const noexcept;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const noexcept;
		};

	private:
		const std::string _name;
		bool _signed;
		const int _grade_to_sign;
		const int _grade_to_execute;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // FORM_H
