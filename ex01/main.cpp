/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:29:00 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/10 11:57:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int		main(void)
{
	int			N = 10;
	std::string	name = "Julia";

	Zombie*	zombies = zombieHorde(N, name);

	for (int i = 0; i < N; i++) {
		zombies[i].announce();
	}

	delete [] zombies;
}
