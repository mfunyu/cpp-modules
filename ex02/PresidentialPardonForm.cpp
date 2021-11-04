/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:56:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/04 14:34:09 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	Form("PresidentialPardonForm", PRESIDENTIALPARDON_SIGN, PRESIDENTIALPARDON_EXEC, "no_target")
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	Form("PresidentialPardonForm", PRESIDENTIALPARDON_SIGN, PRESIDENTIALPARDON_EXEC, other.getTarget())
{
	*this = other;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("PresidentialPardonForm", PRESIDENTIALPARDON_SIGN, PRESIDENTIALPARDON_EXEC, target)
{
}

void	PresidentialPardonForm::beExecuted() const
{
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
