/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 23:49:04 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/29 12:41:41 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
{
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
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		_name = other._name;
	}
	return *this;
}

FragTrap::FragTrap(std::string name)
{
	_name = name;
	_hitPoints = FT_HIT_P;
	_energyPoints = FT_ENERGY_P;
	_attackDamage = FT_ATTACK_D;
	std::cout << "FragTrap constructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Gimme five!!" << std::endl;
}
