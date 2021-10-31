/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:16:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/31 13:46:27 by mfunyu           ###   ########.fr       */
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
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		// const Animal* animal = new Animal(); /* cause compile error */

		dog->makeSound();
		cat->makeSound();

		delete dog;
		delete cat;
	}
}

