/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:37:12 by mott              #+#    #+#             */
/*   Updated: 2024/09/29 12:49:35 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class Data {
	public:
		Data();
		Data(int id, const std::string& name);
		Data(const Data& other);

		~Data();

		Data& operator=(const Data& other);

		int getId() const;
		const std::string& getName() const;

	private:
		int	_id;
		std::string _name;
};

#endif // DATA_H
