/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:03:03 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/10 11:35:00 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int		main( void )
{
	Zombie	*zombie_ptr;

	zombie_ptr = newZombie("Jhon");
	zombie_ptr->announce();
	delete zombie_ptr;

	randomChump("Sum");
}
