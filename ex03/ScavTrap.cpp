/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 23:49:04 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/29 13:16:40 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
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
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		_name = other._name;
	}
	return *this;
}

ScavTrap::ScavTrap(std::string name)
{
	_name = name;
	_hitPoints = ST_HIT_P;
	_energyPoints = ST_ENERGY_P;
	_attackDamage = ST_ATTACK_D;
	std::cout << "ScavTrap constructor called" << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << _name << \
				 " attacks " << target << \
				 ", causing " << _attackDamage << \
				 " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << \
				 " have enterred in Gate keeper mode" << std::endl;
}
