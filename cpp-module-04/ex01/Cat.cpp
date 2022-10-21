/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:09:24 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 21:55:29 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*(other._brain)))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		*_brain = *(other._brain);
		_type = other._type;
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meeeeeeeeeeeeoooooooooooow" << std::endl;
}

std::string const &	Cat::getBrainIdea(unsigned int i) const
{
	return _brain->getIdeas(i);
}

void	Cat::setBrainIdea(unsigned int i, std::string idea)
{
	_brain->setIdeas(i, idea);
}
