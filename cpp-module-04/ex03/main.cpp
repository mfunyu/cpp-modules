/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:44:24 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/17 20:50:35 by mfunyu           ###   ########.fr       */
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

	printSubHeader("Create MateriaSource");
	IMateriaSource* src = new MateriaSource();

	printSubHeader("Call learnMateria()");
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	printSubHeader("Create Character: me");
	ICharacter* me = new Character("me");

	printSubHeader("Equip materias");
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

	printSubHeader("Create Character: Jhon");
	ICharacter* jhon = new Character("Jhon");

	printSubHeader("Unequip materias");
	me->unequip(1);
	me->unequip(4);
	delete tmp1;

	printSubHeader("Use materias");
	for (int i = 0; i < MateriaSource::kMaxMaterials; i++) {
		std::cout << i << ": ";
		me->use(i, *jhon);
	}

	printSubHeader("* End of Scope *");
	delete jhon;
	delete me;
	delete src;
}

void	test_character_copy()
{
	printHeader("Test Character Copy");

	printSubHeader("Create MateriaSource");
	IMateriaSource* src = new MateriaSource();

	printSubHeader("Call learnMateria()");
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	/* [he] ice, cure */
	printSubHeader("Create Character: he");
	Character* he = new Character("he");

	printSubHeader("he Equip Materia");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	he->equip(tmp);
	tmp = src->createMateria("cure");
	he->equip(tmp);

	/* copying he -> she */
	/* [she] ice, cure, cure */
	printSubHeader("Copy Character: she(he)");
	ICharacter* she = new Character(*he);
	printSubHeader("she Equip Materia");
	tmp = src->createMateria("cure");
	she->equip(tmp);

	/* copying he -> me */
	/* [me] ice, cure, ice, ice*/
	printSubHeader("Copy Character: me = he");
	Character me("me");
	me = *he;

	printSubHeader("me Equip Materia");
	tmp = src->createMateria("ice");
	me.equip(tmp);
	tmp = src->createMateria("ice");
	me.equip(tmp);

	printSubHeader("Create Character: nop");
	ICharacter* nop = new Character("nop");

	printSubHeader("Use materias: He");
	for (int i = 0; i < MateriaSource::kMaxMaterials; i++) {
		std::cout << "he [" << i << "]";
		he->use(i, *nop);
	}
	std::cout << std::endl;
	printSubHeader("Use materias: she");
	for (int i = 0; i < MateriaSource::kMaxMaterials; i++) {
		std::cout << "she[" << i << "]";
		she->use(i, *nop);
	}
	std::cout << std::endl;
	printSubHeader("Use materias: me");
	for (int i = 0; i < MateriaSource::kMaxMaterials; i++) {
		std::cout << "me [" << i << "]";
		me.use(i, *nop);
	}
	std::cout << std::endl;
	printSubHeader("* End of Scope *");
	delete nop;
	delete he;
	delete she;
	delete src;
}

void	test_learnMateria()
{
	printHeader("Test Learn Materia");

	printSubHeader("Create MateriaSource");
	IMateriaSource* src = new MateriaSource();

	printSubHeader("Call learnMateria()");
	src->learnMateria(new Cure());
	src->learnMateria(NULL);
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	printSubHeader("Create Character: me");
	ICharacter* me = new Character("me");

	printSubHeader("Equip Materia");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	printSubHeader("Create Character: nop");
	ICharacter* nop = new Character("nop");

	printSubHeader("Use materias");
	me->use(0, *nop);
	me->use(1, *nop);

	printSubHeader("* End of Scope *");
	delete nop;
	delete me;
	delete src;
}

void	test_createMateria()
{
	printHeader("Test Create Materia");

	printSubHeader("Create MateriaSource");
	IMateriaSource* src = new MateriaSource();

	printSubHeader("Call learnMateria()");
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	printSubHeader("Create Character: me");
	ICharacter* me = new Character("me");

	printSubHeader("Equip Materia");
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
	delete tmp;
	*/

	printSubHeader("Create Character: Cathy");
	ICharacter* cathy = new Character("Cathy");

	printSubHeader("Use materias");
	for (int i = -1; i < MateriaSource::kMaxMaterials + 1; i++) {
		std::cout << i << ": ";
		me->use(i, *cathy);
		std::cout << std::endl;
	}

	printSubHeader("* End of Scope *");
	delete cathy;
	delete me;
	delete src;
}

void	descriptive_subject_main()
{
	printHeader("Subject main");

	printSubHeader("Create MateriaSource");
	IMateriaSource* materia_src = new MateriaSource();

	printSubHeader("Call learnMateria()");
	materia_src->learnMateria(new Ice());
	materia_src->learnMateria(new Cure());

	printSubHeader("Create Character: me");
	ICharacter* me = new Character("me");

	printSubHeader("Equip Materia");
	AMateria* tmp;
	tmp = materia_src->createMateria("ice");
	me->equip(tmp);
	tmp = materia_src->createMateria("cure");
	me->equip(tmp);

	printSubHeader("Create Character: Bob");
	ICharacter* Bob = new Character("Bob");

	printSubHeader("Use materia");
	me->use(0, *Bob);
	me->use(1, *Bob);

	printSubHeader("* End of Scope *");
	delete Bob;
	delete me;
	delete materia_src;
}

int		real_subject_main()
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

	return 0;
}

int		main(int ac, char **av)
{
	std::string	test = (ac > 1 ? av[1] : "");

	if (test.empty()) {
		real_subject_main();
	} else if (test == "subject") {
		descriptive_subject_main();
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
