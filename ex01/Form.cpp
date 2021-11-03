/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:49:13 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/03 14:59:59 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>
#include <iostream>

Form::Form() : _isSigned(false), _gradeToSign(GRADE_HIGHEST), _gradeToExec(GRADE_HIGHEST)
{
}

Form::~Form()
{
}

Form::Form(const Form &other) :
	_name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
	*this = other;
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
}

std::string		Form::getName() const
{
	return _name;
}

bool	Form::getIsSigned() const
{
	return _isSigned;
}

int		Form::getGradeToSign() const
{
	return _gradeToSign;
}

int		Form::getGradeToExec() const
{
	return _gradeToExec;
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (_gradeToSign < bureaucrat.getGrade())
	{
		throw GradeTooLowException();
	}
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}


std::ostream	&operator<<(std::ostream &os, const Form& form)
{
	std::cout << "Form " << form.getName() <<\
				 ": required grade to sign" << form.getGradeToSign() <<\
				 ", required grade to execute" << form.getGradeToExec() << std::endl;
	return os;
}
