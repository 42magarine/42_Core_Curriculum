/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:34:29 by mott              #+#    #+#             */
/*   Updated: 2024/09/28 10:38:10 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Intern {
	public:
		Intern();
		Intern(const Intern& other);

		~Intern();

		Intern& operator=(const Intern& other);

		AForm* makeForm(const std::string& form, const std::string& target);

		class FormNotFoundException : public std::exception {
			public:
				const char* what() const noexcept override;
		};

	private:
		static AForm* new_ShrubberyCreation(const std::string& target);
		static AForm* new_RobotomyRequest(const std::string& target);
		static AForm* new_PresidentialPardon(const std::string& target);
};

#endif // INTERN_H
