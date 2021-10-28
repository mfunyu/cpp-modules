/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:29:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/28 16:38:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap() {}

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
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		_name = other._name;
	}
	return *this;
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(10),
										_energyPoints(10),
										_attackDamage(0),
										_name(name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << _name << " attacks " << target << ",";
	std::cout << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	_hitPoints += amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " is repaired,";
	std::cout << " causing " << amount << " points of recovery!" << std::endl;
	_energyPoints += amount;
}

