/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:52:31 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/28 16:41:59 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int		main()
{
	// ClapTrap	claptrap("Sum");

	// claptrap.attack("Jhon");
	// claptrap.beRepaired(42);
	// claptrap.takeDamage(100);

	ScavTrap	scavtrap("Nany");

	scavtrap.attack("Jhon");
	scavtrap.beRepaired(42);
	scavtrap.guardGate();
	scavtrap.takeDamage(100);
}
