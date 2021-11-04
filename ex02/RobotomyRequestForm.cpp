/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:44:39 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/04 14:32:33 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	Form("RobotomyRequestForm", ROBOTOMY_SIGN, ROBOTOMY_EXEC, "no_target")
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	Form("RobotomyRequestForm", ROBOTOMY_SIGN, ROBOTOMY_EXEC, other.getTarget())
{
	*this = other;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("RobotomyRequestForm", ROBOTOMY_SIGN, ROBOTOMY_EXEC, target)
{
}

void	RobotomyRequestForm::beExecuted() const
{
	std::cout << "* Bzzzzzzzzzzzzz *" << std::endl;
	if (std::rand() % 2)
	{
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << getTarget() << " has been falied to be robotomized ..." << std::endl;
	}
}
