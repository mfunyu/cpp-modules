/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:19:50 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/23 14:15:41 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int		main(void)
{
	srand(time(NULL));

	/* Human A: random name, random weapon type */
	std::cout << "[Human A]" << std::endl;
	for (int i = 0; i < 10; i++) {
		Weapon		weapon;
		weapon.setType();
		HumanA		humanA(weapon);
		humanA.attack();
	}

	/* Human B: random name, random weapon type */
	std::cout << "\n[Human B]" << std::endl;
	for (int i = 0; i < 10; i++) {
		HumanB		humanB;
		humanB.attack();
	}
}
