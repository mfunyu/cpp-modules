#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < MAX_MATERIALS; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < MAX_MATERIALS; i++)
	{
		delete _inventory[i];
	}
}

Character::Character(const Character &other)
{
	Character();
	*this = other;
}

Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < MAX_MATERIALS; i++)
		{
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
	for (int i = 0; i < MAX_MATERIALS; i++)
	{
		_inventory[i] = NULL;
	}
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < MAX_MATERIALS; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
	delete m;
}

void Character::unequip(int idx)
{
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < MAX_MATERIALS && _inventory[idx])
	{
		_inventory[idx]->use(target);
	}
}

