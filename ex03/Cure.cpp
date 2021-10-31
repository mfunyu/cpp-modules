#include "Cure.hpp"
#include <iostream>

Cure::Cure()
{
}

Cure::~Cure()
{
}

Cure::Cure(const Cure &other)
{
	*this = other;
}

Cure	&Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
	}
	return *this;
}

AMateria*	Cure::clone() const
{
	Cure*	cloned = new Cure;
	return cloned;
}

void	Cure::use(ICharacter& target)
{
	// std::cout << "* heals " << target.getName() << \
	// 			 "’s wounds *" << std::endl;
	(void)target;
}


