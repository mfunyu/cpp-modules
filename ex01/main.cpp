/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:29:00 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/24 00:45:39 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie*	zombieHorde( int N, std::string name );

int		main(void)
{
	std::string	name = "Julia";
	int			N = 10;

	Zombie*		zombies = zombieHorde(N, name);

	for (int i = 0; i < N; i++) {
		zombies[i].announce();
	}

	delete [] zombies;
}
