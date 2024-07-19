/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:49:52 by mott              #+#    #+#             */
/*   Updated: 2024/07/19 14:31:41 by mott             ###   ########.fr       */
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
	std::cout << "[ DEBUG ]" << std::endl
			  << "I love having extra bacon for my"
			  << " 7XL-double-cheese-triple-pickle-special-ketchup burger."
			  << " I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "[ INFO ]" << std::endl
			  << "I cannot believe adding extra bacon costs more money."
			  << " You didn't put enough bacon in my burger!"
			  << " If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl
			  << "I think I deserve to have some extra bacon for free."
			  << " I've been coming for years whereas you started working"
			  << " here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ]" << std::endl
			  << "This is unacceptable!"
			  << " I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	int i = 0;

	while (i < 4 && level != _level[i]) {
		i++;
	}
	switch (i) {
		case 0:
			(this->*function[0])();
		case 1:
			(this->*function[1])();
		case 2:
			(this->*function[2])();
		case 3:
			(this->*function[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
