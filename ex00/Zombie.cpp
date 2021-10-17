/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:48:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/17 19:41:21 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void	Zombie::announce( void ) const {
	std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie ( std::string name ) : _name(name) {
	return;
}

Zombie::~Zombie () {
	return;
}
