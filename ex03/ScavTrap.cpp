/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 23:49:04 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/14 17:10:31 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
	_hitPoints = _initialHitPoints;
	_energyPoints = _initialEnergyPoints;
	_attackDamage = _initialAttackDamage;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = _initialHitPoints;
	_energyPoints = _initialEnergyPoints;
	_attackDamage = _initialAttackDamage;
	std::cout << "ScavTrap constructor called" << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << _name << \
				 " attacks " << target << \
				 ", causing " << _attackDamage << \
				 (_attackDamage > 2 ? " points" : " point") << \
				 " of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << \
				 " have enterred in Gate keeper mode" << std::endl;
}

void	ScavTrap::showStatus(void)
{
	std::cout << "ScavTrap" << " (" << \
				 "name: " << _name << ", " << \
				 "HP: " << _hitPoints << ", " <<\
				 "EP: " << _energyPoints << ", " <<\
				 "attack damage: " << _attackDamage << \
				 ")" << std::endl;
}
