/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:24:36 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/23 14:16:04 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

void	HumanB::attack() {
	if (!_weapon.getType().empty()) {
		std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
	} else {
		std::cout << _name << " does not have a weapon" << std::endl;
	}
}

HumanB::HumanB() {
	_name = "Jhon_" + std::to_string(rand() % 10000);

	if (rand() % 2)
		_weapon.setType();
	return ;
}

HumanB::~HumanB() {
	return ;
}
