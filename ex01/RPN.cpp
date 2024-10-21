/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:07 by mott              #+#    #+#             */
/*   Updated: 2024/10/21 18:09:58 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
}

RPN::~RPN() {
}

int RPN::compute_rpn(const std::string& argv) {
	for (char c : argv) {
		if (std::isdigit(c)) {
			_stack.push(c - '0');
		}
		else if (isoperator(c) && _stack.size() >= 2) {
			int right = _stack.top();
			_stack.pop();
			int left = _stack.top();
			_stack.pop();
			_stack.push(compute(left, c, right));
		}
		else if (c == ' ') {
			continue;
		}
		else {
			throw std::invalid_argument(RED "Error: Invalid character found" RESET);
		}
	}
	if (_stack.size() != 1) {
		throw std::invalid_argument(RED "Error: Invalid RPN expression" RESET);
	}
	return _stack.top();
}

bool RPN::isoperator(char c) const {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::compute(int left, char c, int right) const {
	switch (c) {
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*':
			return left * right;
		case '/':
			if (right == 0) {
				throw std::invalid_argument(RED "Error: Division by zero" RESET);
			}
			return left / right;
		default:
			throw std::invalid_argument(RED "Error: Unknown operator" RESET);
	}
}
