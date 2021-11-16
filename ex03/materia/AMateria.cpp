/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 22:44:49 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 23:33:51 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

AMateria::AMateria(std::string const& type) : _type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}

std::string const&	AMateria::getType() const
{
	return _type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* use materia for " << target.getName() << \
				 " *" << std::endl;
}

