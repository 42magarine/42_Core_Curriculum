/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:44:29 by mott              #+#    #+#             */
/*   Updated: 2024/09/29 15:00:50 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
	std::srand(std::time(nullptr));

	Base* object = genrate();
	identify(object);
	identify(*object);

	delete object;
	return 0;
}
