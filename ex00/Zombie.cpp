/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:48:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/18 19:56:05 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce( void ) const {
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::nameZombie ( std::string name ) {
	_name = name;
	return;
}

Zombie::Zombie ( std::string name ) : _name(name) {
	return;
}

Zombie::Zombie () {
	return ;
}

Zombie::~Zombie () {
	std::cerr << "Zombie " << _name << " died" << std::endl;
	return;
}
