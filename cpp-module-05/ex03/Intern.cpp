/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:01:30 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/19 23:23:13 by mfunyu           ###   ########.fr       */
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

const char* Intern::UnknownFormException::what() const throw()
{
	return "Unknown form type";
}

template <typename AForm>
Form* Intern::makeAForm(std::string const& target) const
{
	AForm* newForm = new AForm(target);
	return newForm;
}

Form* Intern::unknownForm(std::string const& target) const
{
	(void)target;
	throw UnknownFormException();
	return NULL;
}

Form* Intern::makeForm(
	std::string const formName, std::string const& target) const
{
	std::string formNames[]
		= { "robotomy request", "presidential pardon", "shrubbery creation" };
	Form* (Intern::*makeForms[4])(std::string const&) const = {
		&Intern::makeAForm<RobotomyRequestForm>,
		&Intern::makeAForm<PresidentialPardonForm>,
		&Intern::makeAForm<ShrubberyCreationForm>,
		&Intern::unknownForm
	};

	int i = 0;
	while (i < 3 && formNames[i] != formName) {
		i++;
	}
	Form* createdForm = (this->*makeForms[i])(target);
	std::cout << "Intern creates " << formName << " form" << std::endl;
	return (createdForm);
}
