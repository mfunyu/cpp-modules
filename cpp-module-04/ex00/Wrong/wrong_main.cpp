/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:16:58 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 16:51:06 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>
#include <string>

/* ------------------------------- formatting ------------------------------- */

#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

namespace {
void	printSubHeader(std::string content)
{
	std::cout << COLOR_CYAN <<\
				 "[ " << content << " ]" <<\
				 COLOR_RESET << std::endl;
}
} // namespace

/* -------------------------------------------------------------------------- */
int main()
{
	printSubHeader("WrongAnimal* animal = new WrongAnimal()");
	const WrongAnimal* animal = new WrongAnimal();
	std::cout << "getType(): " << animal->getType() << " " << std::endl;
	std::cout << "makeSound(): ";
	animal->makeSound();
	delete animal;

	printSubHeader("WrongAnimal* A_cat = new WrongCat()");
	const WrongAnimal* A_cat = new WrongCat();
	std::cout << "getType(): " << A_cat->getType() << " " << std::endl;
	std::cout << "makeSound(): ";
	A_cat->makeSound();
	delete A_cat;
}
