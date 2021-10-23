/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:19:50 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/23 14:08:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int		main(int ac, char **av)
{
	/* set name & type from argv */
	if (ac > 2) {
		std::cout << "name: " << av[1] << std::endl;
		std::cout << "type: " << av[2] << std::endl;

		std::cout << "[Human A]" << std::endl;
		HumanA	humanA(av[1], av[2]);
		humanA.attack();

		std::cout << "[Human B]" << std::endl;
		HumanB	humanB(av[1], av[2]);
		humanB.attack();
	}

	srand(time(NULL));

	/* Human A: random name, random weapon type */
	std::cout << "\n[Human A]" << std::endl;
	for (int i = 0; i < 10; i++) {
		HumanA		humanA;
		humanA.attack();
	}

	/* Human B: random name, random weapon type */
	std::cout << "\n[Human B]" << std::endl;
	for (int i = 0; i < 10; i++) {
		HumanB		humanB;
		humanB.attack();
	}
}
