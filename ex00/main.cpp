/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:03:03 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/23 22:30:58 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int		main(void)
{
	Zombie	*zombie_ptr;

	zombie_ptr = newZombie("Jhon");
	zombie_ptr->announce();
	delete zombie_ptr;

	randomChump("Sum");
}
