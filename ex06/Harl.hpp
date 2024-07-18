/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:49:40 by mott              #+#    #+#             */
/*   Updated: 2024/07/18 18:49:42 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <string>

class Harl {
	private:
		void debug();
		void info();
		void warning();
		void error();
		std::string _level[4];
		void (Harl::*function[4])();

	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif
