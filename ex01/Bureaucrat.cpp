/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:37:03 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/19 15:37:42 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	_name(other._name), _grade(other._grade)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	setGrade(grade);
}

std::string const& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrage()
{
	setGrade(_grade - 1);
}

void Bureaucrat::decrementGrage()
{
	setGrade(_grade + 1);
}

bool Bureaucrat::isGradeTooHigh(int grade)
{
	return grade < kGradeHighest;
}

bool Bureaucrat::isGradeTooLow(int grade)
{
	return kGradeLowest < grade;
}

void Bureaucrat::setGrade(int grade)
{
	if (isGradeTooHigh(grade)) {
		throw GradeTooHighException();
	}
	if (isGradeTooLow(grade)) {
		throw GradeTooLowException();
	}
	_grade = grade;
}

void Bureaucrat::signForm(Form& form)
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << _name << " cannot sign " << form.getName() << " because "
				  << e.what() << std::endl;
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException() :
	std::domain_error("Grade is too high") {}

Bureaucrat::GradeTooLowException::GradeTooLowException() :
	std::domain_error("Grade is too low") {}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	std::cout << bureaucrat.getName() << ", bureaucrat grade "
			  << bureaucrat.getGrade();
	return os;
}
