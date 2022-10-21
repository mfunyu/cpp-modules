/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 23:49:04 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/14 17:55:22 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
{
	_hitPoints = _initialHitPoints;
	_energyPoints = _initialEnergyPoints;
	_attackDamage = _initialAttackDamage;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
	*this = other;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
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

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = _initialHitPoints;
	_energyPoints = _initialEnergyPoints;
	_attackDamage = _initialAttackDamage;
	std::cout << "FragTrap constructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Gimme five!!" << std::endl;
}

void	FragTrap::showStatus(void)
{
	std::cout << "FragTrap" << " (" << \
				 "name: " << _name << ", " << \
				 "HP: " << _hitPoints << ", " <<\
				 "EP: " << _energyPoints << ", " <<\
				 "attack damage: " << _attackDamage << \
				 ")" << std::endl;
}
