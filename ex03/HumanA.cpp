/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:24:36 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/10 14:44:06 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) :
	_name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack() {
	std::cout << _name << " attacks with his " <<\
				 _weapon.getType() << std::endl;
}
