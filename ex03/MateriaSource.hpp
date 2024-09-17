/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:37:04 by mott              #+#    #+#             */
/*   Updated: 2024/09/16 14:57:05 by mott             ###   ########.fr       */
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
		void delete_template();
		void copy_template(const MateriaSource& other);

		AMateria* _template[4];
};

#endif // MATERIASOURCE_H
