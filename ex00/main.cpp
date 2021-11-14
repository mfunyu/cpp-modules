/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:52:31 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/14 11:50:07 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int		main()
{
	ClapTrap	claptrap("Sum");

	claptrap.attack("Jhon");
	claptrap.beRepaired(42);
	claptrap.takeDamage(50);
	claptrap.takeDamage(100);
	claptrap.takeDamage(0);
	claptrap.beRepaired(0);
	claptrap.takeDamage(1);
	claptrap.beRepaired(3);
	claptrap.takeDamage(3);
}
