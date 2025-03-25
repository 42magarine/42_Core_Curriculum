/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:46:55 by mott              #+#    #+#             */
/*   Updated: 2024/09/30 13:53:22 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base* genrate() {
	int random_num = std::rand() % 3;

	switch (random_num) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}

	return nullptr;
}

void identify(Base* p) {
	A* pointer_to_a = dynamic_cast<A*>(p);
	B* pointer_to_b = dynamic_cast<B*>(p);
	C* pointer_to_c = dynamic_cast<C*>(p);

	if (pointer_to_a) {
		std::cout << "A" << std::endl;
	}
	else if (pointer_to_b) {
		std::cout << "B" << std::endl;
	}
	else if (pointer_to_c) {
		std::cout << "C" << std::endl;
	}
}

void identify(Base& p) {
	try {
		A& reference_to_a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)reference_to_a;
	}
	catch (std::exception& e) {}

	try {
		B& reference_to_b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)reference_to_b;
	}
	catch (std::exception& e) {}

	try {
		C& reference_to_c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)reference_to_c;
	}
	catch (std::exception& e) {}
}
