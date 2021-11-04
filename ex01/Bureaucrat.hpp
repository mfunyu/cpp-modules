/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:37:06 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/04 18:25:59 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <stdexcept>

# define GRADE_HIGHEST 1
# define GRADE_LOWEST 150

class Bureaucrat;
#include "Form.hpp"

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

		void		setGrade(int grade);
		Bureaucrat();

	public:
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat	&operator=(Bureaucrat const &other);

		Bureaucrat(std::string name, int grade = GRADE_LOWEST);

		std::string		getName() const;
		int				getGrade() const;

		void			incrementGrage();
		void			decrementGrage();

		static bool		isGradeTooHigh(int grade);
		static bool		isGradeTooLow(int grade);

		void			signForm(Form &form);

		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};


std::ostream	&operator<<(std::ostream &os, const Bureaucrat& bureaucrat);

#endif /* BUREAUCRAT_HPP */
