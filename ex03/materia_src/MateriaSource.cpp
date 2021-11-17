/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:56:10 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/17 20:41:48 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < kMaxMaterials; i++)
	{
		_memory[i] = NULL;
	}
	#ifdef TEST
	std::cout << "MateriaSource constructed" << std::endl;
	#endif
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
	if (!a) {
		return ;
	}
	for (int i = 0; i < kMaxMaterials; i++)
	{
		if (!_memory[i])
		{
			_memory[i] = a;
			#ifdef TEST
			std::cout << "Materia \"" << a->getType() << "\" learned" << std::endl;
			#endif
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; _memory[i]; i++)
	{
		if (_memory[i]->getType() == type) {
			#ifdef TEST
			std::cout << "Materia \"" << type << "\" created" << std::endl;
			#endif
			return _memory[i]->clone();
		}
	}
	return 0;
}

