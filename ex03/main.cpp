/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:31:33 by mott              #+#    #+#             */
/*   Updated: 2024/09/17 18:58:39 by mott             ###   ########.fr       */
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
	me->equip(tmp);
	delete tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp;

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	// system("leaks cpp_is_fun");
	return 0;
}

// int main() {
// 	std::cout << std::endl << ">>> learn Materia <<<" << std::endl;
// 	MateriaSource* source = new MateriaSource();
// 	source->learnMateria(new Ice());
// 	source->learnMateria(new Cure());
// 	source->learnMateria(new Ice());
// 	source->learnMateria(new Cure());
// 	source->learnMateria(new Cure());

// 	std::cout << std::endl << ">>> create Materia <<<" << std::endl;
// 	AMateria* created_ice = source->createMateria("ice");
// 	if (created_ice) {
// 		std::cout << "Created Materia type: " << created_ice->getType() << std::endl;
// 	}
// 	else {
// 		std::cout << "Tried to create unknown Materia, returned nullptr." << std::endl;
// 	}

// 	AMateria* created_cure = source->createMateria("cure");
// 	if (created_cure) {
// 		std::cout << "Created Materia type: " << created_cure->getType() << std::endl;
// 	}
// 	else {
// 		std::cout << "Tried to create unknown Materia, returned nullptr." << std::endl;
// 	}

// 	AMateria* created_fire = source->createMateria("fire");
// 	if (created_fire) {
// 		std::cout << "Created Materia type: " << created_fire->getType() << std::endl;
// 	}
// 	else {
// 		std::cout << "Tried to create unknown Materia, returned nullptr." << std::endl;
// 	}

// 	std::cout << std::endl << ">>> create Characters <<<" << std::endl;
// 	ICharacter* me = new Character("me");
// 	ICharacter* bob = new Character("bob");

// 	std::cout << "Created Character name: " << me->getName() << std::endl;
// 	std::cout << "Created Character name: " << bob->getName() << std::endl;

// 	std::cout << std::endl << ">>> equip Materia <<<" << std::endl;
// 	me->equip(created_ice);
// 	me->equip(created_cure);
// 	me->equip(created_fire);
// 	me->equip(created_ice);
// 	me->equip(created_cure);
// 	me->equip(created_fire);

// 	std::cout << std::endl << ">>> use Materia <<<" << std::endl;
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	me->use(2, *bob);
// 	me->use(3, *bob);
// 	me->use(4, *bob);

// 	std::cout << std::endl << ">>> unequip Materia <<<" << std::endl;
// 	AMateria* dropped_materia[2];
// 	dropped_materia[0] = me->getInventory(0);
// 	dropped_materia[1] = me->getInventory(1);
// 	me->unequip(0);
// 	me->unequip(1);

// 	std::cout << std::endl << ">>> assign Ice = Cure <<<" << std::endl;
// 	std::cout << dropped_materia[0]->getType() << std::endl;
// 	std::cout << dropped_materia[1]->getType() << std::endl;
// 	*dropped_materia[0] = *dropped_materia[1];
// 	std::cout << dropped_materia[0]->getType() << std::endl;
// 	std::cout << dropped_materia[1]->getType() << std::endl;

// 	std::cout << std::endl << ">>> copy Character and use Materia <<<" << std::endl;
// 	Character* real_me = dynamic_cast<Character*>(me);
// 	if (real_me) {
// 		ICharacter* another_bob = new Character(*real_me);
// 		another_bob->equip(dropped_materia[0]);
// 		another_bob->use(0, *me);
// 		another_bob->use(1, *me);
// 		another_bob->use(2, *me);
// 		another_bob->use(3, *me);
// 		delete another_bob;
// 	}

// 	std::cout << std::endl << ">>> clean floor <<<" << std::endl;
// 	for (int i = 0; i < 2; i++) {
// 		delete dropped_materia[i];
// 	}

// 	std::cout << std::endl << ">>> clean up <<<" << std::endl;
// 	delete source;
// 	delete created_ice;
// 	delete created_cure;
// 	delete created_fire;
// 	delete me;
// 	delete bob;

// 	// system("leaks cpp_is_fun");
// 	return 0;
// }
