/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:31:33 by mott              #+#    #+#             */
/*   Updated: 2024/09/15 18:03:01 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

// int main() {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");

// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;

// 	// system("leaks name");
// 	return 0;
// }

int main() {
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// While assigning a Materia to another, copying the type doesn't make sense.
	AMateria* ice = src->createMateria("ice");
	AMateria* cure = src->createMateria("cure");

	bob->equip(ice);
	bob->equip(cure);
	bob->use(0, *me);
	bob->use(1, *me);

	*ice = *cure;

	bob->equip(ice);
	bob->equip(cure);
	bob->use(2, *me);
	bob->use(3, *me);

	std::cout << ice->getType() << std::endl;
	std::cout << cure->getType() << std::endl;

	delete me;
	delete bob;
	delete src;

	// system("leaks name");
	return 0;
}
