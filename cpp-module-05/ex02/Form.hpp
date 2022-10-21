#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <stdexcept>
#include <string>

class Form;
#include "Bureaucrat.hpp"

class Form
{
  private:
	std::string const _name;
	bool			  _isSigned;
	int const		  _gradeToSign;
	int const		  _gradeToExec;
	std::string		  _target;
	int				  validateGrade(int grade);
	Form();

  protected:
	virtual void beExecuted() const = 0;

  public:
	virtual ~Form();
	Form(Form const& other);
	Form& operator=(Form const& other);

	Form(
		std::string name, int gradeToSign, int gradeToExec, std::string target);

	std::string const& getName() const;
	bool			   getIsSigned() const;
	int				   getGradeToSign() const;
	int				   getGradeToExec() const;
	std::string const& getTarget() const;

	void beSigned(Bureaucrat const& bureaucrat);

	static bool isGradeTooHigh(int grade);
	static bool isGradeTooLow(int grade);

	void execute(Bureaucrat const& executor) const;

	class GradeTooHighException : public std::domain_error {
	  public:
		GradeTooHighException();
	};
	class GradeTooLowException : public std::domain_error {
	  public:
		GradeTooLowException();
	};
	class FormNotSignedException : public std::exception
	{
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif /* FORM_HPP */
