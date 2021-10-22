/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:02:02 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/22 23:17:16 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie*	zombieHorde( int N, std::string name ){
	Zombie*		zombies = new Zombie[N];

	for (int i = 0; i < N; i++) {
		std::string	zombie_name = (name + '_').append(1, i + '0');
		zombies[i].nameZombie(zombie_name);
	}

	return (zombies);
}
