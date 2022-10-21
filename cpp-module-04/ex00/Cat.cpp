/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:09:24 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 14:30:46 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	*this = other;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meeeeeeeeeeeeoooooooooooow" << std::endl;
}
