/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:25:15 by mott              #+#    #+#             */
/*   Updated: 2024/10/21 17:43:35 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << RED << "Usage: " << argv[0] << " <reverse polish notation>" << RESET << std::endl;
		return 1;
	}

	try {
		RPN rpn;
		std::cout << rpn.compute_rpn(argv[1]) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
