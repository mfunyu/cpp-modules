/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:55:24 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/30 18:06:15 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
}

WrongAnimal::~WrongAnimal()
{
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
	}
	return *this;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
}

std::string WrongAnimal::getType() const
{
	return _type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "??????????" << std::endl;
}
