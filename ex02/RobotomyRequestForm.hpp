/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:04:56 by mott              #+#    #+#             */
/*   Updated: 2024/09/27 14:08:57 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);

		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		void execute(const Bureaucrat& bureaucrat) const override;

	private:
};

#endif // ROBOTOMYREQUESTFORM_H
