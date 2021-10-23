/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:19:40 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/23 14:15:19 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string&	Weapon::getType() {
	return _type;
}

void	Weapon::setType(std::string type) {
	_type = type;
}

void	Weapon::setType() {
	std::string		weapon_types[10] = {
		"pen",
		"spoon",
		"kitchen knife",
		"sword",
		"katana",
		"nuclear weapon",
		"smile",
		"stone",
		"gun",
		"sniper rifle"
	};
	_type = weapon_types[rand() % 10];
}

Weapon::Weapon(std::string type) : _type(type) {

}

Weapon::Weapon() {

}


Weapon::~Weapon() {
	return ;
}
