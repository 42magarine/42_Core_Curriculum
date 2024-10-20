/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:29:16 by mott              #+#    #+#             */
/*   Updated: 2024/10/20 15:29:17 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);

		~PmergeMe();

		PmergeMe& operator=(const PmergeMe& other);

	private:
};

#endif // PMERGEME_H
