/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:56:45 by mott              #+#    #+#             */
/*   Updated: 2024/07/18 18:39:26 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl() {
	_level[0] = "DEBUG";
	_level[1] = "INFO";
	_level[2] = "WARNING";
	_level[3] = "ERROR";

	function[0] = &Harl::debug;
	function[1] = &Harl::info;
	function[2] = &Harl::warning;
	function[3] = &Harl::error;
}

Harl::~Harl() {}

void Harl::debug() {
	std::cout << "I love having extra bacon for my"
				 " 7XL-double-cheese-triple-pickle-special-ketchup burger."
				 " I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money."
				 " You didn't put enough bacon in my burger!"
				 " If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free."
				 " I've been coming for years whereas you started working"
				 " here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable!"
				 " I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	for (int i = 0; i < 4; ++i) {
		if (level == _level[i]) {
			(this->*function[i])();
			return;
		}
	}
}
