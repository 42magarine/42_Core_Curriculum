/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:37:04 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 15:37:05 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include <iostream>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class MateriaSource {
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);

		~MateriaSource();

		MateriaSource& operator=(const MateriaSource& other);

	private:
};

#endif // MATERIASOURCE_H
