/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:08:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 21:06:13 by mfunyu           ###   ########.fr       */
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

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*(other._brain));
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		*_brain = *(other._brain);
		_type = other._type;
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Bow-wow" << std::endl;
}

std::string const &	Dog::getBrainIdea(unsigned int i) const
{
	return _brain->getIdeas(i);
}

void	Dog::setBrainIdea(unsigned int i, std::string idea)
{
	_brain->setIdeas(i, idea);
}
