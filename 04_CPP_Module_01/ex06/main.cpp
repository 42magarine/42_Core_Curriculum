/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:49:24 by mott              #+#    #+#             */
/*   Updated: 2024/08/28 18:48:12 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl Harl;

	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <Filter>" << std::endl;
		return 1;
	}

	Harl.complain(argv[1]);
	return 0;
}
