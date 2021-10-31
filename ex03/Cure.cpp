/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 22:45:24 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/31 22:45:24 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
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
	return new Cure;
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << \
				 "’s wounds *" << std::endl;
}

