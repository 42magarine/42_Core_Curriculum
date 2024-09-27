/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:30:27 by mott              #+#    #+#             */
/*   Updated: 2024/09/27 12:15:28 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Form form_a;
	Form form_b("Einkommensteuer-Erklärung", 42, 42);
	Form form_c(form_b);
	Form form_d;
	form_d = form_a;

	std::cout << form_a << std::endl;
	std::cout << form_b << std::endl;
	std::cout << form_c << std::endl;
	std::cout << form_d << std::endl;

	Bureaucrat bureaucrat_a("Another_Bob", 100);
	Bureaucrat bureaucrat_b("Bob", 10);

	bureaucrat_a.signForm(form_a);
	bureaucrat_a.signForm(form_b);

	bureaucrat_b.signForm(form_c);
	bureaucrat_b.signForm(form_d);

	return 0;
}
