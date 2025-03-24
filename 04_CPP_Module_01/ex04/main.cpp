/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:52:06 by mott              #+#    #+#             */
/*   Updated: 2024/08/28 17:35:35 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename(argv[1]);
	if (filename.empty()) {
		std::cerr << "No filename" << std::endl;
		return 1;
	}
	std::string s1(argv[2]);
	if (s1.empty()) {
		std::cerr << "No s1" << std::endl;
		return 1;
	}
	std::string s2(argv[3]);
	if (s2.empty()) {
		std::cerr << "No s2" << std::endl;
		return 1;
	}

	std::ifstream in_file(filename);
	if (!in_file.is_open()) {
		std::cerr << "Could not open " << filename << std::endl;
		return 1;
	}

	std::stringstream buffer;
	buffer << in_file.rdbuf();
	std::string content;
	content = buffer.str();
	in_file.close();

	size_t pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos) {
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}

	std::ofstream out_file(filename + ".replace");
	if (!out_file.is_open()) {
		std::cerr << "Could not create " << filename << ".replace" << std::endl;
		return 1;
	}
	out_file << content;
	out_file.close();

	system("leaks loser");
	return 0;
}
