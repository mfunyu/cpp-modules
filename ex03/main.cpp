/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:52:31 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/15 23:27:38 by mfunyu           ###   ########.fr       */
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
	std::cout << "\t\"clap\" -> ClapTrap test" << std::endl;
	std::cout << "\t\"scav\" -> ScavTrap test" << std::endl;
	std::cout << "\t\"frag\" -> FragTrap test" << std::endl;
	std::cout << "\t\"diamond\" -> DiamondTrap test" << std::endl;
	std::cout << "\t\"copy\" -> Copy related tests" << std::endl;
	std::cout << "\t  \"copyC\" -> Copy Constructor test" << std::endl;
	std::cout << "\t  \"copy=\" -> Assignment Operator= test" << std::endl;
}
} // namespace

/* -------------------------------------------------------------------------- */

void	testCopyConstructor(void)
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

void	testAssignationOperator()
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

void	testClapTrap()
{
	printHeader("ClapTrap Sum");
	ClapTrap	claptrap("Sum");
	claptrap.showStatus();

	printSubHeader("Base Function: attack()");
	claptrap.attack("Jhon");
	printSubHeader("Base Class Functions");
	claptrap.beRepaired(30);
	claptrap.takeDamage(70);
	printSubHeader("* End of scope *");
}

void	testScavTrap()
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
	printSubHeader("* End of scope *");
}

void	testFragTrap()
{
	printHeader("FragTrap Bob");
	FragTrap	fragtrap("Bob");
	fragtrap.showStatus();

	printSubHeader("Base Function: attack()");
	fragtrap.attack("Julia");
	printSubHeader("Unique Function: highFivesGuys()");
	fragtrap.highFivesGuys();
	printSubHeader("Inherited Functions");
	fragtrap.showStatus();
	fragtrap.takeDamage(50);
	fragtrap.showStatus();
	fragtrap.beRepaired(20);
	printSubHeader("* End of scope *");
}

void	testDiamondTrap()
{
	printHeader("DiamondTrap Jack");
	DiamondTrap	diamondtrap("Jack");
	diamondtrap.showStatus();

	printSubHeader("Inherited Functions: from ClapTrap");
	diamondtrap.takeDamage(0);
	diamondtrap.beRepaired(200);
	printSubHeader("Inherited Function: from ScavTrap");
	diamondtrap.showStatus();
	diamondtrap.attack("Julia");
	diamondtrap.guardGate();
	printSubHeader("Inherited Function: from FragTrap");
	diamondtrap.highFivesGuys();
	printSubHeader("Unique Function: whoAmI()");
	diamondtrap.whoAmI();
	printSubHeader("* End of scope *");
}

int		main(int ac, char **av)
{
	std::string	test = (ac > 1 ? av[1] : "");

	if (test == "clap") {
		testClapTrap();
	} else if (test == "scav") {
		testScavTrap();
	} else if (test == "frag") {
		testFragTrap();
	} else if (test == "diamond") {
		testDiamondTrap();
	} else if (test == "copy") {
		testCopyConstructor();
		std::cout << std::endl;
		testAssignationOperator();
	} else if (test == "copyC") {
		testCopyConstructor();
	} else if (test == "copy=") {
		testAssignationOperator();
	}  else {
		printHelp();
	}
}
