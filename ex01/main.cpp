/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:52:31 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/29 11:58:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int		main()
{
	{
		ClapTrap	claptrap("Sum");

		claptrap.attack("Jhon");
		claptrap.beRepaired(40);
		claptrap.takeDamage(100);
	}
	std::cout << std::endl;
	{
		ScavTrap	scavtrap("Nancy");

		scavtrap.attack("Jhon");
		scavtrap.beRepaired(80);
		scavtrap.guardGate();
		scavtrap.takeDamage(100);
	}
}
