/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:10 by mott              #+#    #+#             */
/*   Updated: 2024/10/21 16:47:39 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <string>
#include <stack>
#include <deque>
#include <stdexcept>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define YELLOW	"\033[33m"

class RPN {
	public:
		RPN() = delete;
		RPN(const std::string& rpn_string);
		RPN(const RPN& other);

		~RPN();

		RPN& operator=(const RPN& other);

		int calculate();

	private:
		std::string _rpn_string;
		std::stack<int> _rpn_stack;
};

#endif // RPN_H
