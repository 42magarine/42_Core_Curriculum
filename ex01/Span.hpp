/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:49:49 by mott              #+#    #+#             */
/*   Updated: 2024/09/30 14:49:50 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Span {
	public:
		Span();
		Span(const Span& other);

		~Span();

		Span& operator=(const Span& other);

	private:
};

#endif // SPAN_H
