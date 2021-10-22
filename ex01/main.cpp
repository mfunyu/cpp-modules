/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:29:00 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/22 23:17:00 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie*	zombieHorde( int N, std::string name );

int		main(void)
{
	Zombie*	zombies = zombieHorde(10, "Julia");

	for (int i = 0; i < 10; i++) {
		zombies[i].announce();
	}

	delete [] zombies;
}
