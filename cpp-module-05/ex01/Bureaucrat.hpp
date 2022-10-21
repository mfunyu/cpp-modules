/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:37:06 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/19 16:06:55 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>

class Bureaucrat;
#include "Form.hpp"

class Bureaucrat
{
  private:
	std::string const _name;
	int				  _grade;

	void setGrade(int grade);
	Bureaucrat();

  public:
	static const int kGradeHighest = 1;
	static const int kGradeLowest  = 150;

	~Bureaucrat();
	Bureaucrat(Bureaucrat const& other);
	Bureaucrat& operator=(Bureaucrat const& other);

	Bureaucrat(std::string name, int grade = kGradeLowest);

	std::string const& getName() const;
	int				   getGrade() const;

	void incrementGrage();
	void decrementGrage();

	static bool isGradeTooHigh(int grade);
	static bool isGradeTooLow(int grade);

	void signForm(Form& form);

	class GradeTooHighException : public std::domain_error {
	  public:
		GradeTooHighException();
	};
	class GradeTooLowException : public std::domain_error {
	  public:
		GradeTooLowException();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif /* BUREAUCRAT_HPP */
