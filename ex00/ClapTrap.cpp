/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:29:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/27 12:44:37 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
	}
	return *this;
}

ClapTrap::ClapTrap(std::string name) : _name(name),
										_hitPoints(10),
										_energyPoints(10),
										_attackDamage(0)
{
	std::cout << "Constructor called" << std::endl;
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << _name << " attacks " << target << ",";
	std::cout << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{


}

void	ClapTrap::beRepaired(unsigned int amount)
{


}

