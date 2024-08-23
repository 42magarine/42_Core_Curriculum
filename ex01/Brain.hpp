/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:02:09 by mott              #+#    #+#             */
/*   Updated: 2024/08/23 15:47:51 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>

class Brain {
	public:
		Brain();
		Brain(const Brain &other);

		~Brain();

		Brain& operator=(const Brain &other);

	// private:
		std::string _ideas[100];
};

#endif // BRAIN_H
