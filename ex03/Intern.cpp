/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:01:30 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/19 14:17:00 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other) {}
	return *this;
}

Form* Intern::makeRobotomyRequestForm(std::string const& target) const
{
	Form* newForm = new RobotomyRequestForm(target);
	return newForm;
}

Form* Intern::makePresidentialPardonForm(std::string const& target) const
{
	Form* newForm = new PresidentialPardonForm(target);
	return newForm;
}

Form* Intern::makeShrubberyCreationForm(std::string const& target) const
{
	Form* newForm = new ShrubberyCreationForm(target);
	return newForm;
}

Form* Intern::makeForm(
	std::string const formName, std::string const& target) const
{
	std::string formNames[]
		= { "robotomy request", "presidential pardon", "shrubbery creation" };
	Form* (Intern::*makeForms[3])(std::string const&) const = {
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm,
		&Intern::makeShrubberyCreationForm,
	};

	for (int i = 0; i < 3; i++) {
		if (formNames[i] == formName) {
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return ((this->*makeForms[i])(target));
		}
	}
	return (NULL);
}
