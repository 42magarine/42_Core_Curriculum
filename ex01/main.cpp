/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:25:15 by mott              #+#    #+#             */
/*   Updated: 2024/10/21 16:48:49 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << RED << "Usage: " << argv[0] << " <reverse polish notation>" << RESET << std::endl;
		return 1;
	}

	try {
		RPN rpn(argv[1]);
		std::cout << YELLOW << rpn.calculate() << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

// 3 + 4				=>	3 4 +
// (3 + 4) x 5			=>	3 4 + 5 x
// (1 + 2) x (3 + 4)	=>	1 2 + 3 4 + x

// compute_rpn(input)
//   stack_init
//   foreach (o in input)
//      switch o
//        isnumber
//          push o
//        isbinoperator
//          right = pop
//          left = pop
//          t = compute(left, o, right)
//          push t
//   return pop

// Beispiel: 23 2 ⋅ 4 −

//            stack : []
// o = 23     stack : [23]
// o = 2      stack : [23,2]
// o = *
// right = 2  stack : [23]
// left = 23  stack : []
// t = 46     stack : [46]
// o = 4      stack : [46,4]
// o = -
// right = 4  stack : [46]
// left = 46  stack : []
// t = 42     stack : [42]
