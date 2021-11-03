/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:37:06 by mfunyu            #+#    #+#             */
/*   Updated: 2021/11/03 11:16:36 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <stdexcept>

# define GRADE_HIGHEST 1
# define GRADE_LOWEST 150

class Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;

	public:
		Bureaucrat();
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
