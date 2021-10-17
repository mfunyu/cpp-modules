/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:58:55 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/17 18:15:34 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// After this, write a function that will create a Zombie, name it, and return it to be
// used somewhere else in your code. The prototype of the function is:

Zombie* newZombie( std::string name ) {
	Zombie *new_zombie;

	new_zombie = new Zombie( name );

	return (new_zombie);
}
