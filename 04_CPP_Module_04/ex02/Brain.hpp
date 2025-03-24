/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:02:09 by mott              #+#    #+#             */
/*   Updated: 2024/09/12 19:09:52 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Brain {
	public:
		Brain();
		Brain(const Brain& other);

		~Brain();

		Brain& operator=(const Brain& other);

		std::string getIdeas(unsigned int i) const;
		void setIdeas(unsigned int i, std::string idea);

	private:
		std::string _ideas[100];
};

#endif // BRAIN_H
