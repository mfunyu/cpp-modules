/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:44:39 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/19 14:15:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	Form(other)
{
	*this = other;
}

RobotomyRequestForm&
RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other) {
		Form::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	Form("RobotomyRequestForm", kGradeToSign, kGradeToExec, target)
{}

void RobotomyRequestForm::beExecuted() const
{
	std::cout << "* Bzzzzzzzzzzzzz *" << std::endl;
	if (std::rand() % 2) {
		std::cout << getTarget() << " has been robotomized successfully!"
				  << std::endl;
	} else {
		std::cout << getTarget() << " has been falied to be robotomized ..."
				  << std::endl;
	}
}
