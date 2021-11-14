/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:29:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/14 12:30:47 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap() :
	_name("no name"),
	_hitPoints(_initialHitPoints),
	_energyPoints(_initialEnergyPoints),
	_attackDamage(_initialAttackDamage)
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

ClapTrap::ClapTrap(std::string name) :
	_name(name),
	_hitPoints(_initialHitPoints),
	_energyPoints(_initialEnergyPoints),
	_attackDamage(_initialAttackDamage)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << _name << \
				 " attacks " << target << \
				 ", causing " << _attackDamage << \
				 (_attackDamage > 2 ? " points" : " point") << \
				 " of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << \
				 " takes " << amount << \
				 (amount > 2 ? " points" : " point") <<\
				 " of damage!";

	if (_hitPoints == 0){
		std::cout << " But ClapTrap is already destroied";
	} else if (_hitPoints <= amount) {
		_hitPoints = 0;
		std::cout << " ClapTrap is destroied!";
	} else {
		_hitPoints -= amount;
	}

	std::cout << " | HP: " << _hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << \
				 " is repaired, causing " << amount << \
				 (amount > 2 ? " points" : " point") << \
				 " of recovery!" << \
				 " | HP: " << _hitPoints << std::endl;
}

void	ClapTrap::showStatus(void)
{
	std::cout << "ClapTrap" << " (" << \
				 "name: " << _name << ", " << \
				 "HP: " << _hitPoints << ", " <<\
				 "EP: " << _energyPoints << ", " <<\
				 "attack damage: " << _attackDamage << \
				 ")" << std::endl;
}
