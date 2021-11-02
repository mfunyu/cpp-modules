/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:44:24 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/02 11:33:36 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void	test_character_copy()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	/* [he] ice, cure */
	Character* he = new Character("he");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	he->equip(tmp);
	tmp = src->createMateria("cure");
	he->equip(tmp);

	/* copying he -> she,  he -> me */
	ICharacter* she = new Character(*he);
	Character me("me");
	me = *he;

	/* [she] ice, cure, cure */
	tmp = src->createMateria("cure");
	she->equip(tmp);

	/* [me] ice, cure, ice, ice*/
	tmp = src->createMateria("ice");
	me.equip(tmp);
	tmp = src->createMateria("ice");
	me.equip(tmp);

	ICharacter* nop = new Character("nop");

	for (int i = 0; i < MAX_MATERIALS; i++) {
		std::cout << i << "==" << std::endl;
		std::cout << "he : ";
		he->use(i, *nop);
		std::cout << "she: ";
		she->use(i, *nop);
		std::cout << "me : ";
		me.use(i, *nop);
	}

	delete nop;
	delete he;
	delete she;
	delete src;
}

void	test_learnMateria()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Cure());
	src->learnMateria(NULL);
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* nop = new Character("nop");

	me->use(0, *nop);
	me->use(1, *nop);

	delete nop;
	delete me;
	delete src;
}

void	test_createMateria()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("none");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* cathy = new Character("Cathy");

	for (int i = -1; i < MAX_MATERIALS + 2; i++) {
		std::cout << i << ": ";
		me->use(i, *cathy);
	}
	std::cout << std::endl;

	delete cathy;
	delete me;
	delete src;
}

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl;
	{
		test_createMateria();
		std::cout << std::endl;
		test_learnMateria();
		std::cout << std::endl;
		test_character_copy();
	}
	return 0;
}
