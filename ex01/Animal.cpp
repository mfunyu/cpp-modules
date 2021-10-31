/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:55:24 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/30 21:35:05 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
}

Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
	}
	return *this;
}

Animal::Animal(std::string type) : _type(type)
{
}

std::string		Animal::getType() const
{
	return _type;
}

void	Animal::makeSound() const
{
	std::cout << "??????????" << std::endl;
}

