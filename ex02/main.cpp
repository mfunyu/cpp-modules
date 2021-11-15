/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:52:31 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/15 22:26:41 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
} // namespace

/* -------------------------------------------------------------------------- */

int		main()
{
	{
		printHeader("ClapTrap Sum");
		ClapTrap	claptrap("Sum");
		claptrap.showStatus();

		printSubHeader("Base Function: attack()");
		claptrap.attack("Jhon");
		printSubHeader("Base Class Functions");
		claptrap.beRepaired(40);
		claptrap.takeDamage(100);
		printSubHeader("* End of scope *");
	}
	{
		printHeader("ScavTrap Nancy");
		ScavTrap	scavtrap("Nancy");
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
}
