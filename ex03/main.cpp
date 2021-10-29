/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:52:31 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/29 12:53:38 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int		main()
{
	{
		ClapTrap	claptrap("Sum");

		claptrap.attack("Jhon");
		claptrap.takeDamage(100);
		claptrap.beRepaired(70);
	}
	std::cout << std::endl;
	{
		ScavTrap	scavtrap("Nany");

		scavtrap.attack("Jhon");
		scavtrap.takeDamage(100);
		scavtrap.guardGate();
		scavtrap.beRepaired(42);
	}
	std::cout << std::endl;
	{
		FragTrap	fragtrap("Bob");

		fragtrap.attack("Julia");
		fragtrap.highFivesGuys();
		fragtrap.takeDamage(50);
		fragtrap.beRepaired(20);
	}
	std::cout << std::endl;
	{
		DiamondTrap	diamondtrap("Bob");

		diamondtrap.attack("Julia");
		diamondtrap.takeDamage(0);
		diamondtrap.beRepaired(200);
		diamondtrap.whoAmI();
	}
	std::cout << std::endl;
	{
		DiamondTrap	d1("Dan");
		DiamondTrap	d2("Lucy");

		d1 = d2;
		d1.whoAmI();
	}
}
