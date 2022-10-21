/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:56:23 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/19 14:14:57 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& other) :
	Form(other)
{
	*this = other;
}

PresidentialPardonForm&
PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other) {
		Form::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	Form("PresidentialPardonForm", kGradeToSign, kGradeToExec, target)
{}

void PresidentialPardonForm::beExecuted() const
{
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox"
			  << std::endl;
}
