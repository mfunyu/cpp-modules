/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:19:40 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/24 16:53:31 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string&	Weapon::getType() const {
	return _type;
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
