/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:09:24 by mfunyu            #+#    #+#             */
/*   Updated: 2021/10/31 18:12:59 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat")
{
	_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*(other._brain));
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		*_brain = *(other._brain);
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meeeeeeeeeeeeoooooooooooow" << std::endl;
}

std::string	Cat::getBrainIdea(unsigned int i) const
{
	return _brain->getIdeas(i);
}

void	Cat::setBrainIdea(unsigned int i, std::string idea)
{
	_brain->setIdeas(i, idea);
}
