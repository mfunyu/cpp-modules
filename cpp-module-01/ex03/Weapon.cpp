/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:19:40 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/11 11:46:38 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon() {}

const std::string&	Weapon::getType() const
{
	return _type;
}

void	Weapon::setType(std::string type)
{
	_type = type;
}
