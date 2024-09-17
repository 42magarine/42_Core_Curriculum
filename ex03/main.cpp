/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:31:33 by mott              #+#    #+#             */
/*   Updated: 2024/09/17 13:19:52 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	(void)tmp;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	// system("leaks name");
	return 0;
}

// While assigning a Materia to another, copying the type doesn't make sense.
// int main() {
// 	AMateria* ice = new Ice();
// 	AMateria* cure = new Cure();

// 	std::cout << "ice type: " << ice->getType() << std::endl;
// 	std::cout << "cure type: " << cure->getType() << std::endl;

// 	*cure = *ice;

// 	std::cout << "ice type: " << ice->getType() << std::endl;
// 	std::cout << "cure type: " << cure->getType() << std::endl;

// 	delete ice;
// 	delete cure;

// 	// system("leaks name");
// 	return 0;
// }
