/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:49:36 by mott              #+#    #+#             */
/*   Updated: 2024/10/17 22:25:24 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

#define RESET  "\033[0m"
#define RED    "\033[31m"
#define YELLOW "\033[33m"
#define MAX_VALUE 8

int main() {
	std::cout << YELLOW << "std::array" << RESET << std::endl;
	std::array<int, MAX_VALUE> array = {1, 2, 3, 4, 5, 6, 7, 8};
	try {
		std::cout << "Found in array: " << *easyfind(array, 1) << std::endl;
		std::cout << "Found in array: " << *easyfind(array, 9) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "std::vector" << RESET << std::endl;
	std::vector<int> vector;
	for (int i = 0; i < MAX_VALUE; i++){
		vector.push_back(i);
	}
	try {
		std::cout << "Found in vector: " << *easyfind(vector, 2) << std::endl;
		std::cout << "Found in vector: " << *easyfind(vector, 9) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "std::deque" << RESET << std::endl;
	std::deque<int> deque;
	for (int i = 0; i < MAX_VALUE; i++){
		deque.push_back(i);
	}
	try {
		std::cout << "Found in deque: " << *easyfind(deque, 3) << std::endl;
		std::cout << "Found in deque: " << *easyfind(deque, 9) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "std::forward_list" << RESET << std::endl;
	std::forward_list<int> forward_list;
	for (int i = 0; i < MAX_VALUE; i++){
		forward_list.push_front(i);
	}
	try {
		std::cout << "Found in forward_list: " << *easyfind(forward_list, 4) << std::endl;
		std::cout << "Found in forward_list: " << *easyfind(forward_list, 9) << std::endl;

	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << "std::list" << RESET << std::endl;
	std::list<int> list;
	for (int i = 0; i < MAX_VALUE; i++){
		list.push_back(i);
	}
	try {
		std::cout << "Found in list: " << *easyfind(list, 5) << std::endl;
		std::cout << "Found in list: " << *easyfind(list, 9) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return 0;
}
