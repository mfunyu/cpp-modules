/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:16:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 21:40:00 by mfunyu           ###   ########.fr       */
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

/*
** [ON COPY]
** cat_original:						cat_copy:
** 	[0] "a brilliant idea"		->		[0] "a brilliant idea"
** 	[1] "an excellent idea"		->		[1] "an excellent idea"
**
** [AFTER COPY]
** cat_original:						cat_copy:
** 	[0] "a brilliant idea"		->		[0] "a brilliant idea"
** 	[1] "a boring idea"			!=		[1] "an excellent idea"
*/
void	testCopyCat()
{
	printHeader("Copy: class Cat");

	printSubHeader("Create cat_original");
	Cat				cat_original;
	unsigned int	index = 0;
	cat_original.setBrainIdea(index, "a brilliant idea");

	printSubHeader("Create cat_copy(cat_original)");
	Cat		cat_copy(cat_original);

	printSubHeader("Before Change");
	std::cout << "cat_original	idea[index]: " << cat_original.getBrainIdea(index) << std::endl;
	std::cout << "cat_copy	idea[index]: " << cat_copy.getBrainIdea(index) << std::endl;

	printSubHeader("Change cat_original");
	cat_original.setBrainIdea(index, "a boring idea");
	std::cout << "cat_original	idea[index]: " << cat_original.getBrainIdea(index) << std::endl;
	std::cout << "cat_copy	idea[index]: " << cat_copy.getBrainIdea(index) << std::endl;

	printSubHeader("* End of Scope *");
}

/*
** [ON COPY]
** dog_original:						dog_copy:
** 	[0] "a brilliant idea"		->		[0] "a brilliant idea"
** 	[1] "an excellent idea"		->		[1] "an excellent idea"
**
** [AFTER COPY]
** dog_original:						dog_copy:
** 	[0] "a brilliant idea"		->		[0] "a brilliant idea"
** 	[1] "a boring idea"			!=		[1] "an excellent idea"
*/
void	testCopyDog()
{
	printHeader("Copy: class Dog");

	Dog		dog_original;
	dog_original.setBrainIdea(0, "a brilliant idea");
	dog_original.setBrainIdea(1, "an excellent idea");
	Dog		dog_copy;

	dog_copy = dog_original;

	std::cout << "dog_original	idea 0: " << dog_original.getBrainIdea(0) << std::endl;
	std::cout << "dog_copy	idea 0: " << dog_copy.getBrainIdea(0) << std::endl;
	dog_original.setBrainIdea(1, "a boring idea");
	std::cout << "dog_original	idea 1: " << dog_original.getBrainIdea(1) << std::endl;
	std::cout << "dog_copy	idea 1: " << dog_copy.getBrainIdea(1) << std::endl;
}

void	subjectRequiredTest()
{
	printHeader("Test Required in Subject");

	int		n = 4;
	Animal* animals[4];

	for (int i = 0; i < n; i++)
	{
		if (i % 2) {
			printSubHeader("Create Cat");
			animals[i] = new Cat();
		}
		else {
			printSubHeader("Create Dog");
			animals[i] = new Dog();
		}
	}

	printSubHeader("Delete All");
	for (int i = 0; i < n; i++)
	{
		delete animals[i];
	}
}

int		main()
{
	subjectRequiredTest();
	testCopyCat();
	testCopyDog();
}
