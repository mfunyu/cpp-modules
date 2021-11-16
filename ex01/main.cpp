/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:16:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 21:20:41 by mfunyu           ###   ########.fr       */
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

void	main2()
{
	std::cout << std::endl;
	{
		Cat		cat_original;
		cat_original.setBrainIdea(0, "a brilliant idea");
		cat_original.setBrainIdea(1, "an excellent idea");
		Cat		cat_copy(cat_original);
		/*
		[ON COPY]
		cat_original:						cat_copy:
			[0] "a brilliant idea"		->		[0] "a brilliant idea"
			[1] "an excellent idea"		->		[1] "an excellent idea"

		[AFTER COPY]
		cat_original:						cat_copy:
			[0] "a brilliant idea"		->		[0] "a brilliant idea"
			[1] "a boring idea"			!=		[1] "an excellent idea"
		*/

		std::cout << "cat_original	idea 0: " << cat_original.getBrainIdea(0) << std::endl;
		std::cout << "cat_copy	idea 0: " << cat_copy.getBrainIdea(0) << std::endl;
		cat_original.setBrainIdea(1, "a boring idea");
		std::cout << "cat_original	idea 1: " << cat_original.getBrainIdea(1) << std::endl;
		std::cout << "cat_copy	idea 1: " << cat_copy.getBrainIdea(1) << std::endl;
	}
	std::cout << std::endl;
	{
		Dog		dog_original;
		dog_original.setBrainIdea(0, "a brilliant idea");
		dog_original.setBrainIdea(1, "an excellent idea");
		Dog		dog_copy;

		dog_copy = dog_original;
		/*
		[ON COPY]
		dog_original:						dog_copy:
			[0] "a brilliant idea"		->		[0] "a brilliant idea"
			[1] "an excellent idea"		->		[1] "an excellent idea"

		[AFTER COPY]
		dog_original:						dog_copy:
			[0] "a brilliant idea"		->		[0] "a brilliant idea"
			[1] "a boring idea"			!=		[1] "an excellent idea"
		*/

		std::cout << "dog_original	idea 0: " << dog_original.getBrainIdea(0) << std::endl;
		std::cout << "dog_copy	idea 0: " << dog_copy.getBrainIdea(0) << std::endl;
		dog_original.setBrainIdea(1, "a boring idea");
		std::cout << "dog_original	idea 1: " << dog_original.getBrainIdea(1) << std::endl;
		std::cout << "dog_copy	idea 1: " << dog_copy.getBrainIdea(1) << std::endl;
	}
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
	main2();
}
