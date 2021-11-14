/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 23:49:04 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/29 00:35:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : _name("no_name")
{
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::_initialHitPoints;
	_energyPoints = ScavTrap::_initialEnergyPoints;
	_attackDamage = FragTrap::_initialAttackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	*this = other;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		_name = other._name;
		ClapTrap::_name = other.ClapTrap::_name;
	}
	return *this;
}

DiamondTrap::DiamondTrap(std::string name) : _name(name)
{
	ClapTrap::_name = name + "_clap_name";
	_hitPoints = FragTrap::_initialHitPoints;
	_energyPoints = ScavTrap::_initialEnergyPoints;
	_attackDamage = FragTrap::_initialAttackDamage;
	std::cout << "DiamondTrap constructor called" << std::endl;
}


void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << _name << \
				 ". My ClapTrap name is " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::showStatus(void)
{
	std::cout << "DiamondTrap" << " (" << \
				 "name: " << _name << ", " << \
				 "ClapTrap name: " << ClapTrap::_name << ", " << \
				 "HP: " << _hitPoints << ", " <<\
				 "EP: " << _energyPoints << ", " <<\
				 "attack damage: " << _attackDamage << \
				 ")" << std::endl;
}
