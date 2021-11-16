/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:27:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/16 21:07:07 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
}

Brain	&Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (unsigned int i = 0; i < kMaxIdeas; i++)
		{
			_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

std::string	Brain::getIdeas(unsigned int i) const
{
	return _ideas[i];
}

void	Brain::setIdeas(unsigned int i, std::string idea)
{
	_ideas[i] = idea;
}
