/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 22:45:44 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 23:36:12 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice &other)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = other;
}

Ice	&Ice::operator=(const Ice &other)
{
	std::cout << "Ice assignment operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

AMateria*	Ice::clone() const
{
	return new Ice(*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << \
				 " *" << std::endl;
}
