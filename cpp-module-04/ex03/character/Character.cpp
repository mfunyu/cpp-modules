/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:55:49 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/17 22:54:06 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

Character::Character() : _name("no_name")
{
	for (int i = 0; i < MateriaSource::kMaxMaterials; i++)
	{
		_inventory[i] = NULL;
	}
	#ifdef TEST
	std::cout << "Character " << _name << " constructed" << std::endl;
	#endif
}

Character::~Character()
{
	for (int i = 0; i < MateriaSource::kMaxMaterials; i++)
	{
		delete _inventory[i];
	}
}

Character::Character(const Character &other) : _name(other._name)
{
	for (int i = 0; i < MateriaSource::kMaxMaterials; i++)
	{
		_inventory[i] = NULL;
	}
	*this = other;
	#ifdef TEST
	std::cout << "Character " << _name << " constructed through copy" << std::endl;
	#endif
}

Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < MateriaSource::kMaxMaterials; i++)
		{
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < MateriaSource::kMaxMaterials; i++)
	{
		_inventory[i] = NULL;
	}
	#ifdef TEST
	std::cout << "Character " << _name << " constructed" << std::endl;
	#endif
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m) {
		return ;
	}
	for (int i = 0; i < MateriaSource::kMaxMaterials; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			#ifdef TEST
			std::cout << _name << " equipped Materia \"" << m->getType() << "\"" << std::endl;
			#endif
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (is_idx_in_range(idx))
	{
		_inventory[idx] = NULL;
		for (int i = idx; i < MateriaSource::kMaxMaterials - 1; i++)
		{
			_inventory[i] = _inventory[i + 1];
			_inventory[i + 1] = NULL;
		}
		#ifdef TEST
		std::cout << "Materia at index " << idx << " unequipped" << std::endl;
		#endif
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (is_idx_in_range(idx) && _inventory[idx])
	{
		_inventory[idx]->use(target);
	}
}

bool	Character::is_idx_in_range(int idx)
{
	return (0 <= idx && idx < MateriaSource::kMaxMaterials);
}
