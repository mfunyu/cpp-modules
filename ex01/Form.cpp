/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:49:13 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/03 18:41:10 by mfunyu           ###   ########.fr       */
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
	_name(name), _isSigned(false), _gradeToSign(validateGrade(gradeToSign)), _gradeToExec(validateGrade(gradeToExec))
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

bool	Form::isGradeTooHigh(int grade)
{
	return grade < GRADE_HIGHEST;
}

bool	Form::isGradeTooLow(int grade)
{
	return GRADE_LOWEST < grade;
}

int		Form::validateGrade(int grade)
{
	if (isGradeTooHigh(grade))
	{
		throw GradeTooHighException();
	}
	if (isGradeTooLow(grade))
	{
		throw GradeTooLowException();
	}
	return grade;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}


std::ostream	&operator<<(std::ostream &os, const Form& form)
{
	std::cout << form.getName() <<\
				 ": grade to sign = " << form.getGradeToSign() <<\
				 ", grade to execute = " << form.getGradeToExec();
	if (form.getIsSigned())
	{
		std::cout << " (signed)";
	}
	else
	{
		std::cout << " (unsigned)";
	}
	return os;
}
