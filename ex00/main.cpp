/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:03:03 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/17 18:13:14 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int		main(void) {
	Zombie	*zombie_ptr;

	zombie_ptr = newZombie("Jhon");
	zombie_ptr->announce();
	delete zombie_ptr;

	randomChump("Sum");
}
