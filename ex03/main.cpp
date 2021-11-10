/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:19:50 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/10 20:10:34 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/* -------------------------------------------------------------------------- */

#define COLOR_CYAN "\033[36m"
#define COLOR_RESET "\033[0m"

void	print(std::string testName)
{
	std::cout << COLOR_CYAN << testName
				<< COLOR_RESET << std::endl;
}

/* -------------------------------------------------------------------------- */

int main()
{
	{
		print("[ Human A: Case of Bob ]");

		Weapon club = Weapon("crude spiked club");
		print(" ** Weapon Created ** ");
		std::cout << "Weapon type: " << club.getType() << std::endl;

		HumanA bob("Bob", club);
		print(" ## Bob Born with the Weapon ## ");
		bob.attack();

		club.setType("kitchen knife");
		print(" ** Weapon Type Changed ** ");
		std::cout << "Weapon type: " << club.getType() << std::endl;

		print(" ## Bob's Weapon Automatically Changed ## ");
		bob.attack();
	}
	{
		print("\n[ Human B: Case of Jim ]");

		Weapon club = Weapon("crude spiked club");
		print(" ** Weapon Created ** ");
		std::cout << club.getType() << " created" << std::endl;

		HumanB jim("Jim");
		print(" ## Jim Born without Weapon ## ");
		jim.attack();

		jim.setWeapon(club);
		print(" ## Weapon Given to Jim ##  ");
		jim.attack();

		club.setType("spoon");
		print(" ** Weapon Type Changed ** ");
		std::cout << "Weapon type: " << club.getType() << std::endl;

		print(" ## Bob's Weapon Automatically Changed ## ");
		jim.attack();
	}
}
