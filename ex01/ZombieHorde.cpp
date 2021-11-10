/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:02:02 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/10 11:57:29 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {
	Zombie*	zombies = new Zombie[N];

	for (int i = 0; i < N; i++) {
		char		zombie_id = i + '0';
		std::string	zombie_name = name + "_" + zombie_id;
	
		zombies[i].nameZombie(zombie_name);
	}

	return zombies;
}
