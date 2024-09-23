/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:39:21 by mott              #+#    #+#             */
/*   Updated: 2024/09/23 18:05:54 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <exception>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, unsigned int grade);
		Bureaucrat(const Bureaucrat& other);

		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		std::string getName() const;
		unsigned int getGrade() const;
		void incrementGrade();
		void decrementGrade();

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
		unsigned int _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_H
