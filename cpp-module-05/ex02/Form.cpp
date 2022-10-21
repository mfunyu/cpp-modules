/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:49:13 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/19 16:03:03 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Form::~Form() {}

Form::Form(const Form& other) :
	_name(other._name), _isSigned(other._isSigned),
	_gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec),
	_target(other._target)
{
	*this = other;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other) {
		_isSigned = other._isSigned;
		_target	  = other._target;
	}
	return *this;
}

Form::Form(
	std::string name, int gradeToSign, int gradeToExec, std::string target) :
	_name(name),
	_isSigned(false), _gradeToSign(validateGrade(gradeToSign)),
	_gradeToExec(validateGrade(gradeToExec)), _target(target)
{}

std::string const& Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExec() const
{
	return _gradeToExec;
}

std::string const& Form::getTarget() const
{
	return _target;
}

void Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (_gradeToSign < bureaucrat.getGrade()) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

bool Form::isGradeTooHigh(int grade)
{
	return grade < Bureaucrat::kGradeHighest;
}

bool Form::isGradeTooLow(int grade)
{
	return Bureaucrat::kGradeLowest < grade;
}

int Form::validateGrade(int grade)
{
	if (isGradeTooHigh(grade)) {
		throw GradeTooHighException();
	}
	if (isGradeTooLow(grade)) {
		throw GradeTooLowException();
	}
	return grade;
}

void Form::execute(Bureaucrat const& executor) const
{
	if (!_isSigned) {
		throw FormNotSignedException();
	}
	if (_gradeToExec < executor.getGrade()) {
		throw GradeTooLowException();
	}
	beExecuted();
}

Form::GradeTooHighException::GradeTooHighException() :
	std::domain_error("Grade is too high") {}

Form::GradeTooLowException::GradeTooLowException() :
	std::domain_error("Grade is too low") {}

const char* Form::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	std::cout << form.getName() << ": grade to sign = " << form.getGradeToSign()
			  << ", grade to execute = " << form.getGradeToExec()
			  << ", signed = " << (form.getIsSigned() ? "true" : "false")
			  << ", target = " << form.getTarget();
	return os;
}
