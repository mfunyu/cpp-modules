#include "Character.hpp"

Character::Character()
{
}

Character::~Character()
{
}

Character::Character(const Character &other)
{
	*this = other;
}

Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Character::Character(std::string name) : _name(name)
{
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	(void)m;
}

void Character::unequip(int idx)
{
	(void)idx;
}

void Character::use(int idx, ICharacter& target)
{
	(void)idx;
	(void)target;
}

