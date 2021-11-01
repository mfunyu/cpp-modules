/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:16:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/01 17:56:30 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		Animal* animals[4];

		for (int i = 0; i < 2; i++)
		{
			animals[i] = new Cat();
		}
		for (int i = 2; i < 4; i++)
		{
			animals[i] = new Dog();
		}
		for (int i = 0; i < 4; i++)
		{
			delete animals[i];
		}
	}
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

