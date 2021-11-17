/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 22:44:49 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/17 22:43:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria &other) : _type(other._type) {}

AMateria	&AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

AMateria::AMateria(std::string const& type) : _type(type) {}

std::string const&	AMateria::getType() const
{
	return _type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* use materia for " << target.getName() << \
				 " *" << std::endl;
}

