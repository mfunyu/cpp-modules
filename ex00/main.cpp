/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:16:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 16:54:44 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/* ------------------------------- formatting ------------------------------- */

#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

namespace {
void	printHeader(std::string content)
{
	std::cout << std::endl;
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
} // namespace

/* -------------------------------------------------------------------------- */

void	subject_main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void	original_tests(void)
{
	printSubHeader("Animal* animal = new Animal()");
	const Animal* animal = new Animal();
	std::cout << "getType(): " << animal->getType() << " " << std::endl;
	std::cout << "makeSound(): ";
	animal->makeSound();
	delete animal;

	printSubHeader("Animal* A_dog = new Dog()");
	const Animal* A_dog = new Dog();
	std::cout << "getType(): " << A_dog->getType() << " " << std::endl;
	std::cout << "makeSound(): ";
	A_dog->makeSound();
	delete A_dog;

	printSubHeader("Animal* A_cat = new Cat()");
	const Animal* A_cat = new Cat();
	std::cout << "getType(): " << A_cat->getType() << " " << std::endl;
	std::cout << "makeSound(): ";
	A_cat->makeSound();
	delete A_cat;
}

int		main()
{
	printHeader("Subject main");
	subject_main();

	printHeader("Original tests");
	original_tests();
}
