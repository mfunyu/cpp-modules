/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:24:36 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/23 14:10:12 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

void	HumanA::attack() {
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, std::string type) : _name(name) {
	_weapon.setType(type);
	return ;
}

HumanA::HumanA() {
	_name = "Sum_" + std::to_string(rand() % 10000);

	_weapon.setType(false);
	return ;
}

HumanA::~HumanA() {
	return ;
}
