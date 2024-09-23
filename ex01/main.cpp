/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:30:27 by mott              #+#    #+#             */
/*   Updated: 2024/09/23 19:09:01 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Form a;
	std::cout << a << std::endl;

	Form b("Einkommensteuer-Erklärung", 42, 42);
	std::cout << b << std::endl;

	Form c(b);
	std::cout << c << std::endl;

	Form d;
	d = a;
	std::cout << d << std::endl;

	return 0;
}
