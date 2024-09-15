/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:37:04 by mott              #+#    #+#             */
/*   Updated: 2024/09/15 17:00:01 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

#define RESET  "\033[0m"
#define YELLOW "\033[33m"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);

		~MateriaSource();

		MateriaSource& operator=(const MateriaSource& other);

		void learnMateria(AMateria* m) override;
		AMateria* createMateria(const std::string& type) override;

	private:
		AMateria* _template[4];
};

#endif // MATERIASOURCE_H
