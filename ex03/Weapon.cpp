/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:19:40 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/23 14:46:08 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string&	Weapon::getType() {
	std::string&	typeREF = _type;

	return typeREF;
}

void	Weapon::setType(std::string type) {
	_type = type;
}

Weapon::Weapon(std::string type) : _type(type) {
	return ;
}

Weapon::Weapon() {
	return ;
}

Weapon::~Weapon() {
	return ;
}
