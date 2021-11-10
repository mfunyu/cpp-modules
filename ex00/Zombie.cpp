/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:48:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/10 11:37:16 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie () {}

Zombie::~Zombie () {
	std::cout << "Zombie " << _name << " died" << std::endl;
}

Zombie::Zombie ( std::string name ) : _name(name) {}

void	Zombie::nameZombie ( std::string name ) {
	_name = name;
}

void	Zombie::announce( void ) const {
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
