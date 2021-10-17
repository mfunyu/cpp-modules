/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:48:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/13 00:19:37 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce( void ) {
	std::cout << "<" << _zombie_name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie ( std::string name ) : _zombie_name(name) {
	return;
}

Zombie::~Zombie () {
	return;
}
