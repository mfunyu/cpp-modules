/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:44:24 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 23:21:07 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

/* ------------------------------- formatting ------------------------------- */

#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

namespace {
void	printHeader(std::string content)
{
	std::cout << COLOR_CYAN <<\
				 "*** " << content << " ***" <<\
				 COLOR_RESET << std::endl;
}

void	printSubHeader(std::string content)
{
	std::cout << COLOR_CYAN <<\
				 "[ " << content << " ]" <<\
				 COLOR_RESET << std::endl;
}

void	printHelp(void)
{
	std::cout << "usage: ./a.out [testname]\n" << std::endl;
	std::cout << "  \"testnames\"" << std::endl;
	std::cout << "\t\"subject\"\t-> run subject's main" << std::endl;
	std::cout << "\t\"createMateria\"\t-> check create Materia" << std::endl;
	std::cout << "\t\"learnMateria\"\t-> check learn Materia" << std::endl;
	std::cout << "\t\"characterCopy\"\t-> check character Copy" << std::endl;
	std::cout << "\t\"unequip\"\t-> check unequip" << std::endl;
}
} // namespace

/* -------------------------------------------------------------------------- */

void	test_unequip()
{
	printHeader("Test Unequip");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	AMateria* tmp1;
	tmp1 = src->createMateria("cure");
	me->equip(tmp1);
	AMateria* tmp2;
	tmp2 = src->createMateria("ice");
	me->equip(tmp2);
	AMateria* tmp3;
	tmp3 = src->createMateria("cure");
	me->equip(tmp3);

	ICharacter* bob = new Character("bob");

	me->unequip(1);
	me->unequip(4);
	delete tmp1;

	for (int i = 0; i < MateriaSource::kMaxMaterials; i++) {
		std::cout << i << ": ";
		me->use(i, *bob);
	}

	delete bob;
	delete me;
	delete src;
}

void	test_character_copy()
{
	printHeader("Test Character Copy");
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

	for (int i = 0; i < MateriaSource::kMaxMaterials; i++) {
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
	printHeader("Test Learn Materia");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Cure());
	src->learnMateria(NULL);
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

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
	printHeader("Test Create Materia");
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
	/*
	tmp = src->createMateria("cure");
	me->equip(tmp);
	delete tmp
	*/

	ICharacter* cathy = new Character("Cathy");

	for (int i = -1; i < MateriaSource::kMaxMaterials + 2; i++) {
		std::cout << i << ": ";
		me->use(i, *cathy);
	}
	std::cout << std::endl;

	delete cathy;
	delete me;
	delete src;
}

void	subject_main()
{
	printHeader("Subject main");
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

	printSubHeader("Use materia");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int		main(int ac, char **av)
{
	std::string	test = (ac > 1 ? av[1] : "");

	if (test == "subject") {
		subject_main();
	} else if (test == "createMateria") {
		test_createMateria();
	} else if (test == "learnMateria") {
		test_learnMateria();
	} else if (test == "characterCopy") {
		test_character_copy();
	} else if (test == "unequip") {
		test_unequip();
	} else {
		printHelp();
	}
	return 0;
}
