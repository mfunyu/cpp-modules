/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 22:45:24 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 23:34:55 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure &other)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = other;
}

Cure	&Cure::operator=(const Cure &other)
{
	std::cout << "Cure assignment operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

AMateria*	Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << \
				 "'s wounds *" << std::endl;
}

