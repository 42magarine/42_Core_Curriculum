/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:05:03 by mott              #+#    #+#             */
/*   Updated: 2024/09/27 14:09:07 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"
#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);

		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		void execute(const Bureaucrat& bureaucrat) const override;

	private:
};

#endif // SHRUBBERYCREATIONFORM_H
