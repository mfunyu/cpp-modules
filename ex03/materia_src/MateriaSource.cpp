/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:56:10 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 23:01:41 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < kMaxMaterials; i++)
	{
		_memory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < kMaxMaterials; i++)
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
		for (int i = 0; i < kMaxMaterials; i++)
		{
			_memory[i] = other._memory[i];
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* a)
{
	for (int i = 0; i < kMaxMaterials; i++)
	{
		if (!_memory[i])
		{
			_memory[i] = a;
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; _memory[i]; i++)
	{
		if (_memory[i]->getType() == type)
			return _memory[i]->clone();
	}
	return 0;
}

