/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:08:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/31 13:22:00 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog")
{
	_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		delete _brain;
		if (other._brain)
		{
			_brain = new Brain();
			for (int i = 0; i < TOTAL_IDEAS; i++)
			{
				_brain->setIdeas(i, other._brain->getIdeas(i));
			}
		}
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Bow-wow" << std::endl;
}

std::string	Dog::getBrainIdea(unsigned int i) const
{
	return _brain->getIdeas(i);
}

void	Dog::setBrainIdea(unsigned int i, std::string idea)
{
	_brain->setIdeas(i, idea);
}
