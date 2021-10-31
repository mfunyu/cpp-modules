/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:08:53 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/31 18:11:37 by mfunyu           ###   ########.fr       */
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
	_brain = new Brain(*(other._brain));
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		*_brain = *(other._brain);
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
