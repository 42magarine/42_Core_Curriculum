/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:10 by mott              #+#    #+#             */
/*   Updated: 2024/10/20 15:29:11 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class RPN {
	public:
		RPN();
		RPN(const RPN& other);

		~RPN();

		RPN& operator=(const RPN& other);

	private:
};

#endif // RPN_H
