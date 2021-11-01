/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 22:44:49 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/01 17:42:17 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(std::string const& type) : _type(type)
{
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

