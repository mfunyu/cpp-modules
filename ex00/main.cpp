/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:52:31 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/14 12:33:23 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

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
	printHeader("ClapTrap Sum");
	ClapTrap	sum("Sum");
	sum.showStatus();

	printSubHeader("Attack");
	sum.attack("Jhon");

	printSubHeader("Be repaired");
	sum.showStatus();
	sum.beRepaired(42);

	printSubHeader("Take Damage");
	sum.showStatus();
	sum.takeDamage(50);

	printSubHeader("Destroied");
	sum.showStatus();
	sum.takeDamage(100);

	printSubHeader("Further Damage");
	sum.showStatus();
	sum.takeDamage(0);

	printSubHeader("Random");
	sum.beRepaired(0);
	sum.beRepaired(3);
	sum.showStatus();
	sum.takeDamage(1);
	sum.showStatus();
	sum.takeDamage(3);
}
