/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:07 by mott              #+#    #+#             */
/*   Updated: 2024/10/21 16:51:12 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string& argv) : _rpn_string(argv) {
}

RPN::RPN(const RPN& other) : _rpn_string(other._rpn_string), _rpn_stack(other._rpn_stack) {
}

RPN::~RPN() {
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_rpn_string = other._rpn_string;
		_rpn_stack = other._rpn_stack;
	}
	return *this;
}

int RPN::calculate() {

	return 1;
}
