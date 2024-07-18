/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:52:06 by mott              #+#    #+#             */
/*   Updated: 2024/07/18 16:36:19 by mott             ###   ########.fr       */
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

	std::ifstream inFile(filename);
	if (!inFile.is_open()) {
		std::cerr << "Could not open " << filename << std::endl;
		return 1;
	}
	// is anything of the following possible like "outFile << content;" ?
	// inFile >> content;
	// inFile.rdbuf() >> content;
	// inFile.str() >> content;

	std::stringstream buffer;
	buffer << inFile.rdbuf();
	std::string content;
	// std::string temp;
	content = buffer.str();

	// do {
	// 	std::getline(inFile, temp);
	// 	content += temp;
	// } while (!temp.empty());

	inFile.close(); // necessary?

	size_t pos = 0;
	// while (pos = content.find(s1) != content.npos) { here .find() always start at the beginning of the string?
	// while (pos = content.find(s1, pos) != std::string::npos) { why does it work? how does the program know which string?
	while ((pos = content.find(s1, pos)) != content.npos) {
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}

	std::ofstream outFile(filename + ".replace");
	if (!outFile.is_open()) {
		std::cerr << "Could not create " << filename << ".replace" << std::endl;
		inFile.close();
		return 1;
	}
	outFile << content;
	outFile.close(); // necessary?

	// system("leaks Sed_is_for_losers");
	return 0;
}
