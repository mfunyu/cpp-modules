#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Form;
# include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExec;

	public:
		Form();
		~Form();
		Form(Form const &other);
		Form	&operator=(Form const &other);

		Form(std::string name, int gradeToSign, int gradeToExec);

		std::string		getName() const;
		bool			getIsSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExec() const;

		void			beSigned(Bureaucrat const &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};


std::ostream	&operator<<(std::ostream &os, const Form& form);

#endif /* FORM_HPP */
