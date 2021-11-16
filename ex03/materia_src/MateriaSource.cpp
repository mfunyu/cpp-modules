/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:56:10 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 23:30:42 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < kMaxMaterials; i++)
	{
		_memory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < kMaxMaterials; i++)
	{
		delete _memory[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	MateriaSource();
	*this = other;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
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

