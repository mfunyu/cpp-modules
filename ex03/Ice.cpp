#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice::Ice(const Ice &other)
{
	*this = other;
}

Ice	&Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
	}
	return *this;
}

AMateria*	Ice::clone() const
{
	Ice*	cloned = new Ice();
	return cloned;
}

void	Ice::use(ICharacter& target)
{
	// std::cout << "* shoots an ice bolt at " << target \
	// 			 " *" << std::endl;
	(void)target;
}
