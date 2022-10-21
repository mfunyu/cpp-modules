/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:16:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 21:54:05 by mfunyu           ###   ########.fr       */
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

void	printHelp()
{
	std::cout << "usage: ./a.out [testname]\n" << std::endl;
	std::cout << "  \"testnames\"" << std::endl;
	std::cout << "\t\"subject\"\t-> run test required in the subject" << std::endl;
	std::cout << "\t\"copyCat\"\t-> check deep copy for class Cat" << std::endl;
	std::cout << "\t\"copyDog\"\t-> check deep copy for class Dog" << std::endl;
}
} // namespace

/* -------------------------------------------------------------------------- */

/*
** [ON COPY]
** cat_original:						cat_copy:
** 	[0] "a brilliant idea"		->		[0] "a brilliant idea"
**
** [AFTER COPY]
** cat_original:						cat_copy:
** 	[0] "a brilliant idea"		->		[0] "an excellent idea""
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

	printSubHeader("Change cat_copy");
	cat_copy.setBrainIdea(index, "a fantastic idea");
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

	printSubHeader("Create dog_original");
	Dog				dog_original;
	unsigned int	index = 0;
	dog_original.setBrainIdea(index, "a brilliant idea");

	printSubHeader("Create dog_copy(dog_original)");
	Dog		dog_copy(dog_original);

	printSubHeader("Before Change");
	std::cout << "dog_original	idea[index]: " << dog_original.getBrainIdea(index) << std::endl;
	std::cout << "dog_copy	idea[index]: " << dog_copy.getBrainIdea(index) << std::endl;

	printSubHeader("Change dog_copy");
	dog_copy.setBrainIdea(index, "a boring idea");
	std::cout << "dog_original	idea[index]: " << dog_original.getBrainIdea(index) << std::endl;
	std::cout << "dog_copy	idea[index]: " << dog_copy.getBrainIdea(index) << std::endl;

	printSubHeader("* End of Scope *");
}

void	subjectRequiredTest()
{
	printHeader("Test Required in Subject");

	int		n = 4;
	Animal* animals[4];

	printSubHeader("* Create In Loop *");
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

	printSubHeader("* Delete In Loop *");
	for (int i = 0; i < n; i++)
	{
		printSubHeader("Delete One");
		delete animals[i];
	}
}

int		main(int ac, char **av)
{
	std::string	test = (ac > 1 ? av[1] : "");
	if (test == "subject") {
		subjectRequiredTest();
	} else if (test == "copyCat") {
		testCopyCat();
	} else if (test == "copyDog") {
		testCopyDog();
	} else {
		printHelp();
	}
}
