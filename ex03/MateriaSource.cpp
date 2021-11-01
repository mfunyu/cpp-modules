#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < MAX_MATERIALS; i++)
	{
		_memory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIALS; i++)
	{
		delete _memory[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	MateriaSource();
	*this = other;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < MAX_MATERIALS; i++)
		{
			_memory[i] = other._memory[i];
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* a)
{
	for (int i = 0; i < MAX_MATERIALS; i++)
	{
		if (!_memory[i])
		{
			_memory[i] = a;
			return ;
		}
	}
	delete a;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; _memory[i]; i++)
	{
		if (_memory[i]->getType() == type)
			return _memory[i]->clone();
	}
	return NULL;
}

