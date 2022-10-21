/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:08:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 21:55:18 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*(other._brain)))
{
	std::cout << "Dog copy constructor called" << std::endl;
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
