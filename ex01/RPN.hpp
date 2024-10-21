/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:10 by mott              #+#    #+#             */
/*   Updated: 2024/10/21 18:09:51 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <string>
#include <stack>
#include <deque>
#include <cctype>
#include <stdexcept>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"

class RPN {
	public:
		RPN();
		RPN(const RPN& other) = delete;

		~RPN();

		RPN& operator=(const RPN& other) = delete;

		int compute_rpn(const std::string& argv);

	private:
		bool isoperator(char c) const;
		int compute(int left, char c, int right) const;

		std::stack<int> _stack;
};

#endif // RPN_H
