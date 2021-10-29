/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:29:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/29 12:46:16 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
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

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << _name << \
				 " attacks " << target << \
				 ", causing " << _attackDamage << \
				 " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << "ClapTrap " << _name << \
				 " takes " << amount << \
				 " points of damage! HP: " << _hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << \
				 " is repaired, causing " << amount << \
				 " points of recovery! HP: " << _hitPoints << std::endl;
}
