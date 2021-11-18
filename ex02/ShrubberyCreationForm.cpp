/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:55:35 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/18 20:10:57 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <string>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Form(other)
{
	*this = other;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		Form::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("ShrubberyCreationForm", kGradeToSign, kGradeToExec, target)
{
}

void	ShrubberyCreationForm::beExecuted() const
{
	std::string		filename = getTarget() + "_shrubbery";
	std::ofstream	ofs(filename);

	if (ofs.fail())
	{
		std::exit(1);
	}
	ofs << ". \n\
|-- Bureaucrat.cpp \n\
|-- Bureaucrat.hpp \n\
|-- Form.cpp \n\
|-- Form.hpp \n\
|-- Makefile \n\
|-- PresidentialPardonForm.cpp \n\
|-- PresidentialPardonForm.hpp \n\
|-- RobotomyRequestForm.cpp \n\
|-- RobotomyRequestForm.hpp \n\
|-- ShrubberyCreationForm.cpp \n\
|-- ShrubberyCreationForm.hpp \n\
|-- main.cpp \n\
`-- objs \n\
    |-- Bureaucrat.o \n\
    |-- Form.o \n\
    |-- PresidentialPardonForm.o \n\
    |-- RobotomyRequestForm.o \n\
    |-- ShrubberyCreationForm.o \n\
    `-- main.o \n\
\n\
1 directory, 18 files";
}
