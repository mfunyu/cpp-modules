/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:08:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/02 12:32:25 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
}

Dog::~Dog()
{
}

Dog::Dog(const Dog &other)
{
	*this = other;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Bow-wow" << std::endl;
}
