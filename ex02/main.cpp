/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:52:31 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/29 00:37:56 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int		main()
{
	/*
	ClapTrap	claptrap("Sum");

	claptrap.attack("Jhon");
	claptrap.beRepaired(42);
	claptrap.takeDamage(100);

	ScavTrap	scavtrap("Nany");

	scavtrap.attack("Jhon");
	scavtrap.beRepaired(42);
	scavtrap.guardGate();
	scavtrap.takeDamage(100);
	*/
	FragTrap	fragtrap("Bob");

	fragtrap.attack("Julia");
	fragtrap.highFivesGuys();
	fragtrap.takeDamage(50);
	fragtrap.beRepaired(20);
}
