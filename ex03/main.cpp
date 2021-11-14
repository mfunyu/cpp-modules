/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:52:31 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/14 21:59:48 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

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

void	testCopies(void)
{
	{
		printHeader("DiamondTrap Copy Check");
		printSubHeader("Create A DiamondTrap 'original'");
		DiamondTrap	original("original");

		printSubHeader("Modify 'original'");
		original.showStatus();
		original.takeDamage(10);
		original.showStatus();

		printSubHeader("Construct 'copy' using 'original'");
		DiamondTrap	copy(original);
		copy.showStatus();

		printSubHeader("* End of scope *");
	}
	{
		printHeader("DiamondTrap Copy Assignation Operator =");
		printSubHeader("Create A DiamondTrap 'original'");
		DiamondTrap	original("original");

		printSubHeader("Modify 'original'");
		original.showStatus();
		original.takeDamage(10);
		original.showStatus();

		printSubHeader("Create Another DiamondTrap 'copy'");
		DiamondTrap	copy("copy");

		printSubHeader("'copy' before copy");
		copy.showStatus();
		copy = original;
		printSubHeader("'copy' after Copy");
		copy.showStatus();

		printSubHeader("* End of scope *");
	}
}

int		main()
{
	{
		printHeader("ClapTrap Sum");
		ClapTrap	claptrap("Sum");
		claptrap.showStatus();

		printSubHeader("Base Function: attack()");
		claptrap.attack("Jhon");
		printSubHeader("Base Class Functions");
		claptrap.beRepaired(30);
		claptrap.takeDamage(70);
	}
	{
		printHeader("ScavTrap Nancy");
		ScavTrap	scavtrap("Nany");
		scavtrap.showStatus();

		printSubHeader("Override Function: attack()");
		scavtrap.attack("Jhon");
		printSubHeader("Unique Function: guardGate()");
		scavtrap.guardGate();
		printSubHeader("Inherited Functions");
		scavtrap.showStatus();
		scavtrap.beRepaired(10);
		scavtrap.showStatus();
		scavtrap.takeDamage(20);
	}
	{
		printHeader("FragTrap Bob");
		FragTrap	fragtrap("Bob");

		fragtrap.attack("Julia");
		fragtrap.highFivesGuys();
		fragtrap.takeDamage(50);
		fragtrap.beRepaired(20);
	}
	{
		printHeader("FragTrap Jack");
		DiamondTrap	diamondtrap("Jack");
		diamondtrap.showStatus();

		printSubHeader("Inherited Functions");
		diamondtrap.takeDamage(0);
		diamondtrap.beRepaired(200);
		printSubHeader("Inherited Function: from ScavTrap");
		diamondtrap.showStatus();
		diamondtrap.attack("Julia");
		diamondtrap.guardGate();
		printSubHeader("Inherited Function: from FlagTrap");
		diamondtrap.highFivesGuys();
		printSubHeader("Unique Function: whoAmI()");
		diamondtrap.whoAmI();
	}
	testCopies();
}
